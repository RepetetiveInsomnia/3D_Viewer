#ifndef SRC_TESTS_S21_ED_VIEWER_TEST_H_
#define SRC_TESTS_S21_ED_VIEWER_TEST_H_

#include <check.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#include "../3DViewer/viewerlib/viewerlib.h"

Suite *suite_read_obj(void);
Suite *suite_zoom_obj(void);
Suite *suite_move_x(void);
Suite *suite_move_y(void);
Suite *suite_move_z(void);
Suite *suite_rotation_by_ox(void);
Suite *suite_rotation_by_oy(void);
Suite *suite_rotation_by_oz(void);
// Suite *suite_free_obj(void);

// pp

#endif  // SRC_TESTS_S21_ED_VIEWER_TEST_H_
