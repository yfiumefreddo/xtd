# string_assert_does_not_contain

Shows how to use [xtd::tunit::string_assert::does_not_contain](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1tunit_1_1string__assert.html#a45a645260827fdfe499f279a87b77311) method.

## Sources

[src/string_assert_does_not_contain.cpp](src/string_assert_does_not_contain.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that does_not_contain the project and type the following:

```cmake
xtdc run
```

## Output

```
Start 2 tests from 1 test case
Run tests:
  SUCCEED test.test_case_succeed (0 ms total)
  FAILED  test.test_case_failed (0 ms total)
    Expected: not string containing "alu"
    But was:  "value"
    Stack Trace: in |---OMITTED---|/string_assert_does_not_contain.cpp:16

Test results:
  SUCCEED 1 test.
  FAILED  1 test.
End 2 tests from 1 test case ran. (0 ms total)
```
