
#include "test.hpp"

/**
 * @brief Print a highlighted, dash-padded test-case banner to stdout.
 *
 * Builds the label `"---[" + test_case + "]"`, then pads it on the right with
 * `'-'` characters to a field width of 75. The resulting line is wrapped in the
 * highlight escape sequences `HIGHLIGHT_START` / `HIGHLIGHT_END` and followed
 * by a newline.
 *
 * @param test_case The human-readable test case name to display inside the brackets.
 * @return `void`
 *
 * @pre `HIGHLIGHT_START` and `HIGHLIGHT_END` are defined (ANSI SGR sequences or empty strings).
 * @note Requires `<iostream>`, `<iomanip>`, `<sstream>`, and `<string>`.
 * @warning Padding is computed before highlighting; ANSI escape codes do not affect the
 *          width calculation. If `test_case` is long enough that the composed label length
 *          is ≥ 75, no trailing dashes will be added.
 * @example
 *   // Prints a highlighted line like:
 *   // ---[test case 01]-----------------------------------------------------------
 *   test("test case 01");
*/

void test(const std::string& test_case) {

    // declaring os string stream variable
    std::ostringstream os_string;
    // daclaring and intializing string varibale to build the first part
    const std::string label = std::string("---[") + test_case + "]";

    // building the complete string
    os_string
        << std::left
        << std::setfill('-')
        << std::setw(75)
        << label;

    // displaying the string with formating
    std::cout
        << HIGLIGHT_START
        << os_string.str()
        << HIGLIGHT_END
        << "\n";
}
