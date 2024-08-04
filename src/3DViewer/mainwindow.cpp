#include "mainwindow.h"

#include <QDateTime>

#include "ui/viewFieldGL/viewfieldgl.h"
#include "ui_mainwindow.h"

extern "C" {
#include "3rdparty/gif.h"
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  setWindowTitle("3DViewer v1.0");
  readConfig();

  QObject::connect(ui->newFileButton, &QPushButton::clicked, this,
                   &MainWindow::newFileButton);
  QObject::connect(ui->gifButton, &QPushButton::clicked, this,
                   &MainWindow::writeGifButton);
  QObject::connect(ui->screenshotButton, &QPushButton::clicked, this,
                   &MainWindow::screenshotButton);

  // GLWIdget slots to mainwindow ui signals
  QObject::connect(ui->scaleSlider, &QSlider::valueChanged, ui->openGLWidget,
                   &ViewFieldGL::scaleChange);

  QObject::connect(ui->xOffstSpBox,
                   QOverload<double>::of(&QDoubleSpinBox::valueChanged),
                   ui->openGLWidget, &ViewFieldGL::xOffsetChange);
  QObject::connect(ui->yOffstSpBox,
                   QOverload<double>::of(&QDoubleSpinBox::valueChanged),
                   ui->openGLWidget, &ViewFieldGL::yOffsetChange);
  QObject::connect(ui->zOffstSpBox,
                   QOverload<double>::of(&QDoubleSpinBox::valueChanged),
                   ui->openGLWidget, &ViewFieldGL::zOffsetChange);

  QObject::connect(ui->xRotSpBox,
                   QOverload<double>::of(&QDoubleSpinBox::valueChanged),
                   ui->openGLWidget, &ViewFieldGL::xRotChange);
  QObject::connect(ui->yRotSpBox,
                   QOverload<double>::of(&QDoubleSpinBox::valueChanged),
                   ui->openGLWidget, &ViewFieldGL::yRotChange);
  QObject::connect(ui->zRotSpBox,
                   QOverload<double>::of(&QDoubleSpinBox::valueChanged),
                   ui->openGLWidget, &ViewFieldGL::zRotChange);

  QObject::connect(ui->projectionTypeCmbBox, &QComboBox::currentTextChanged,
                   ui->openGLWidget, &ViewFieldGL::projectTypeChange);
  QObject::connect(ui->vrtxShapeCmbBox, &QComboBox::currentTextChanged,
                   ui->openGLWidget, &ViewFieldGL::vertexTypeChange);
  QObject::connect(ui->edgesTypeCmbBox, &QComboBox::currentTextChanged,
                   ui->openGLWidget, &ViewFieldGL::edgeTypeChange);

  QObject::connect(ui->vrtxSizeSlider, &QSlider::valueChanged, ui->openGLWidget,
                   &ViewFieldGL::vertexSizeChange);
  QObject::connect(ui->edgesWidthSlider, &QSlider::valueChanged,
                   ui->openGLWidget, &ViewFieldGL::edgeWidthChange);

  QObject::connect(ui->bgClrButton, &QToolButton::clicked, this,
                   &MainWindow::backColorChange);
  QObject::connect(ui->vrtxColorButton, &QToolButton::clicked, this,
                   &MainWindow::vertexColorChange);
  QObject::connect(ui->edgesColorButton, &QToolButton::clicked, this,
                   &MainWindow::edgeColorChange);
}

void MainWindow::parseFile() {
  objData_t *data = ui->openGLWidget->data();
  free_3d(data);
  if (*m_filename == '\0' || !m_filename) {
    ui->filePathLabel->setText("File is not choosen");
  } else {
    std::locale prev_locale = std::locale::global(std::locale::classic());
    parcer(m_filename, data);
    std::locale::global(prev_locale);
    setDefault();
    ui->openGLWidget->toNormilize();
    double step = ui->openGLWidget->normalization() / (float)20;
    ui->xOffstSpBox->setSingleStep(step);
    ui->yOffstSpBox->setSingleStep(step);
    ui->zOffstSpBox->setSingleStep(step);
  }
}

void MainWindow::writeConfig() {
  QFile file(".config.json");

  if (file.open(QIODevice::WriteOnly | QFile::Text)) {
    QJsonObject projObject;
    projObject = ui->openGLWidget->toJson();
    file.write(QJsonDocument(projObject).toJson());
    file.close();
  }
}

void MainWindow::readConfig() {
  QFile file(".config.json");
  if (file.open(QIODevice::ReadOnly | QFile::Text)) {
    QByteArray saveData = file.readAll();
    QJsonDocument loadDoc(QJsonDocument::fromJson(saveData));
    ui->openGLWidget->fromJson(loadDoc.object());
    file.close();
    ui->openGLWidget->update();
  }
  setUI();
}

void MainWindow::setUI() {
  auto glW = ui->openGLWidget;
  ui->scaleSlider->setValue(glW->scale());
  ui->vrtxSizeSlider->setValue(glW->vertexSize());
  ui->edgesWidthSlider->setValue(glW->edgeWidth());
  if (glW->edgeType() == SOLID) {
    ui->edgesTypeCmbBox->setCurrentText("Solid");
  } else {
    ui->edgesTypeCmbBox->setCurrentText("Dotted");
  }

  if (glW->vertexType() == NONE) {
    ui->vrtxShapeCmbBox->setCurrentText("None");
  } else if (glW->vertexType() == CIRCLE) {
    ui->vrtxShapeCmbBox->setCurrentText("Circle");
  } else {
    ui->vrtxShapeCmbBox->setCurrentText("Square");
  }

  if (glW->projType() == PARALLEL) {
    ui->projectionTypeCmbBox->setCurrentText("Parallel");
  } else {
    ui->projectionTypeCmbBox->setCurrentText("Central");
  }

  ui->xRotSpBox->setValue(glW->xRot());
  ui->yRotSpBox->setValue(glW->yRot());
  ui->zRotSpBox->setValue(glW->zRot());

  ui->xOffstSpBox->setValue(glW->xOffst());
  ui->yOffstSpBox->setValue(glW->yOffst());
  ui->zOffstSpBox->setValue(glW->zOffst());

  setColorButton(ui->bgClrButton, glW->bgColor());
  setColorButton(ui->vrtxColorButton, glW->vertexColor());
  setColorButton(ui->edgesColorButton, glW->edgeColor());
}

void MainWindow::setDefault() {
  ui->openGLWidget->setDefault();
  setUI();
}

MainWindow::~MainWindow() {
  writeConfig();
  delete ui;
}

void MainWindow::setColorButton(QToolButton *btn, QColor color) {
  QPixmap px(20, 20);
  px.fill(color);
  btn->setIcon(px);
}

void MainWindow::newFileButton() {
  QFile inputFile(QFileDialog::getOpenFileName(this, tr("Open File"), "",
                                               tr("Object files (*.obj)")));

  QFileInfo info(inputFile);
  QString absoluteFilePath = info.absoluteFilePath();

  QByteArray byteArray = absoluteFilePath.toLocal8Bit();
  if (byteArray.size() && QFile::exists(absoluteFilePath)) {
    m_filename = byteArray.data();
    ui->filePathLabel->setText(info.fileName());
    parseFile();
    ui->openGLWidget->update();
  }
}

void MainWindow::writeGifButton() {
  QString temp = QCoreApplication::applicationDirPath();
  // TODO: write splitting by "/" from end to 3DViewer
  temp.chop(9);

  QString timeStr =
      QDateTime::currentDateTime().toString("yyyy-MM-dd_hh.mm.ss");
  QString initName = temp + "data-samples/" + "3DV_gif_" + timeStr + ".gif";
  QString fileName = QFileDialog::getSaveFileName(
      this, tr("Save gif"), initName, tr("Gif files (*.gif)"));

  if (!fileName.isEmpty()) {
    QImage img = ui->openGLWidget->grabFramebuffer();
    QPainter painter(&img);
    QImage img640_480;
    QTime dieTime;
    int width = 640;
    int height = 480;
    GifWriter gif;
    QByteArray ba = fileName.toLocal8Bit();
    const char *c_str = ba.data();
    GifBegin(&gif, c_str, width, height, 5);

    for (int i = 0; i < 85; ++i) {
      ui->openGLWidget->render(&painter);
      img640_480 = img.scaled(QSize(640, 480));
      GifWriteFrame(&gif, img640_480.bits(), width, height, 6);
      dieTime = QTime::currentTime().addMSecs(100);
      while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
    }

    GifEnd(&gif);
    QMessageBox msgBox;
    msgBox.setText("GIF saved successfully.");
    msgBox.exec();
  } else {
    QMessageBox::warning(this, "", "Failed to save gif.");
  }
}

void MainWindow::screenshotButton() {
  QString temp = QCoreApplication::applicationDirPath();
  temp.chop(9);
  QString timeStr =
      QDateTime::currentDateTime().toString("yyyy-MM-dd_hh:mm:ss.jpg");
  QString initName = temp + "data-samples/" + "3DV_ScreenShot_" + timeStr;
  QString fileName = QFileDialog::getSaveFileName(
      this, tr("Save screenshot"), initName, tr("Image Files (*.jpg *.bmp)"));

  if (!fileName.isEmpty()) {
    QImage img = ui->openGLWidget->grabFramebuffer();
    if (img.save(fileName)) {
      QMessageBox msgBox;
      msgBox.setText("Screenshot saved successfully.");
      msgBox.exec();
    } else {
      QMessageBox::warning(this, "", "Failed to save screenshot.");
    }
  }
}

void MainWindow::backColorChange() {
  auto glW = ui->openGLWidget;
  glW->backColorChange();
  setColorButton(ui->bgClrButton, glW->bgColor());
}

void MainWindow::vertexColorChange() {
  auto glW = ui->openGLWidget;
  glW->vertexColorChange();
  setColorButton(ui->vrtxColorButton, glW->vertexColor());
}

void MainWindow::edgeColorChange() {
  auto glW = ui->openGLWidget;
  glW->edgeColorChange();
  setColorButton(ui->edgesColorButton, glW->edgeColor());
}
