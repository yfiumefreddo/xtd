# valid_is_negative

Shows how to use [xtd::tunit::valid::is_negative](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1tunit_1_1valid.html#aed095681e8c47aa686b95ccd33732792) method.

## Sources

[src/valid_is_negative.cpp](src/valid_is_negative.cpp)

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
    Expected: negative
    But was:  1
    Stack Trace: in |---OMITTED---|/valid_is_negative.cpp:16

Test results:
  SUCCEED 1 test.
  FAILED  1 test.
End 2 tests from 1 test case ran. (0 ms total)
```
