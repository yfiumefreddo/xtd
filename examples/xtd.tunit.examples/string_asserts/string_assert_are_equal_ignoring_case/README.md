# string_assert_are_equal_ignoring_case

Shows how to use [xtd::tunit::string_assert::are_equal_ignoring_case](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1tunit_1_1string__assert.html#aad86b74256b792f6bb7e752303d94ca4) method.

## Sources

[src/string_assert_are_equal_ignoring_case.cpp](src/string_assert_are_equal_ignoring_case.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:

```cmake
xtdc run
```

## Output

```
Start 2 tests from 1 test case
Run tests:
  SUCCEED test.test_case_succeed (0 ms total)
  FAILED  test.test_case_failed (0 ms total)
    Expected: "key", ignoring case
    But was:  "VALUE"
    Stack Trace: in |---OMITTED---|/string_assert_are_equal_ignoring_case.cpp:16

Test results:
  SUCCEED 1 test.
  FAILED  1 test.
End 2 tests from 1 test case ran. (0 ms total)
```
