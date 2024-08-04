#include "s21_ed_viewer_test.h"

int main() {
  int failed = 0;
  int passed = 0;
  Suite *matrix_tests[] = {
      suite_read_obj(),       suite_zoom_obj(),       suite_move_x(),
      suite_move_y(),         suite_move_z(),         suite_rotation_by_ox(),
      suite_rotation_by_oy(), suite_rotation_by_oz(), NULL};

  for (int i = 0; matrix_tests[i] != NULL; i++) {
    SRunner *sr = srunner_create(matrix_tests[i]);

    srunner_set_fork_status(sr, CK_NOFORK);
    srunner_run_all(sr, CK_NORMAL);

    failed += srunner_ntests_failed(sr);
    passed += srunner_ntests_run(sr) - srunner_ntests_failed(sr);
    srunner_free(sr);
  }

  printf("========= PASSED: %d =========\n", passed);
  printf("========= FAILED: %d =========\n", failed);

  return failed == 0 ? 0 : 1;
}
