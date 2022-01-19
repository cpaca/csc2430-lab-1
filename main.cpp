#include <iostream>
#include <fstream>
#include <string>
using std::cout;
using std::cerr;
using std::cin;
using std::endl;
using std::ifstream;
using std::string;
using std::getline;

/*
 * Before running the program take a look at the following two pages:
 * --> getline:    http://cplusplus.com/reference/string/string/getline/
 * --> operator>>: http://cplusplus.com/reference/string/string/operator%3E%3E/
 *
 * 1. When does the getline function stop reading from the input stream?
 * getline() stops reading after it finds a new line, specifically "\n"
 * 2. When does the operator>> stop reading from the input stream?
 * It stops when it finds any whitespace. This typically means spaces or newlines
 * but given that it says "whitespace" I assume the zero-width space ​ counts too.
 * Huh. Apparantly CLion actually renders the zero width space as "ZWSP". Neat!
 */

int main() {
    /*
     * When you run the program,
     * try the following names:
     * not-here.txt
     * --> The program should respond:
     *     Unable to open not-here.txt
     * --> 3. Any idea why the output is shown in a different color?
     * It was sent to cerr instead of cout. While cout uses white outputs, cerr uses red outputs.
     * Presumably, cerr uses red outputs so you can see that it's red.
     *
     * data.txt
     * 4. Was it able to open it? Any idea why?
     * No. I'd guess maybe because it's running in this file (main.cpp) or inside the cmake-build-debug file.
     * Put another way, [dir]/main.cpp/data.txt doesn't exist.
     *
     * ../data.txt
     * This time the program must've been able to open the file
     * 5. Why do you think that is? A hint: where is the program running from?
     * It probably worked this time because [dir]/main.cpp/.. = [dir].
     */

    string filename;
    cout << "Please input file name: ";
    cin >> filename;

    ifstream input;
    string string1, string2;

    input.open(filename);
    if (input.fail()){
        cerr << "Unable to open " << filename << endl;
        return 1;
    }
    /*
     * Notice in this part of the program that we are reading from the file
     * first by using the stream extraction operator >>
     * and then using the function getline
     * Notice the output. 
     * 6. Why do you think the output looks like that?
     * Probably because << reads "An" then getline() reads "\n", outputs "" (nothing), and stops.
     */
    input >> string1;
    getline(input, string2);
    cout << "input << string1;   getline(input, string2);" << endl;
    cout << "string1 = " << string1 << endl;
    cout << "string2 = " << string2 << endl;

    input.close(); // to reset
    input.open(filename);
    // Just in case
    if (input.fail()){
        cerr << "Unable to open " << filename << endl;
        return 1;
    }
    /*
     * Now the program is reading from the file but this time
     * first by using getline and then by using the stream operator >>
     * Is it different from the output you saw from the previous code?
     * 7. Why is that?
     * Probably because getline() reads "An\n", removes "An\n", returns "An",
     * and then the >> operator reads "Amazing"
     */
    getline(input, string1);
    input >> string2;
    cout << "getline(input, string2);   input << string1;" << endl;
    cout << "string1 = " << string1 << endl;
    cout << "string2 = " << string2 << endl;

    input.close();

    return 0;
}
