#include <iostream>
#include <string>
using namespace std;

string adjustStringLength(string binaryNumber, int count) {

	// adds leading zeros to the string to adjust length

	while (count > 0) {		
		binaryNumber = '0' + binaryNumber;
		count--;
	}

	return binaryNumber;
}

int convertToBaseTen(string input) {

	// takes a binary string as an input and returns the value as a base 10 integer

	int count = input.length() - 1;
	int addAmt = 1;
	string number = "";
	int total = 0;

	for (int i = count; i > -1; i--) {

		number = input[i];
		
		if (number == "1") {
			total = total + addAmt;
		}

		addAmt = addAmt * 2;

	}

	return total;
}

string addNumbers(string num1, string num2) {

	string output = "";
	int lenNum1 = num1.length();
	int lenNum2 = num2.length();
	bool fin = false;
	string number1 = "";
	string number2 = "";
	string sum = "0";
	string carry = "0";


	// iterates through each pair of binary digits and calculates the total as a binary number

	
	for (int i = lenNum1 - 1; i > -1; i--) {

		fin = false;

		number1 = num1[i];
		number2 = num2[i];

		if (fin == false) {

			if (carry == "0") {

				if (number1 == "0") {

					if (number2 == "0") {
						sum = "0";
						carry = "0";
						fin = true;
					}
					if (number2 == "1") {
						sum = "1";
						carry = "0";
						fin = true;
					}

				}

				if (number1 == "1") {

					if (number2 == "0") {
						sum = "1";
						carry = "0";
						fin = true;
					}
					if (number2 == "1") {
						sum = "0";
						carry = "1";
						fin = true;
					}
				}
			}

		}

		if (fin == false) {

			if (carry == "1") {

				if (number1 == "0") {

					if (number2 == "0") {
						sum = "1";
						carry = "0";
						fin = true;
					}
					if (number2 == "1") {
						sum = "0";
						carry = "1";
						fin = true;
					}

				}

				if (number1 == "1") {

					if (number2 == "0") {
						sum = "0";
						carry = "1";
						fin = true;
					}
					if (number2 == "1") {
						sum = "1";
						carry = "1";
						fin = true;
					}
				}
			}
		}


		output = sum + output;

		if (i == 0) {
			if (carry == "1") {

				output = carry + output;
			}

		}
	}
	
	return output;
}


int calculate(string input1, string input2, bool dispCalc) {

	//string input1 = "1000101";
	//string input2 = "1011101";
	string outputStrng = "";
	int outputInt = 0;
	int lenInput1 = input1.length();
	int lenInput2 = input2.length();
	int lenOutput = 0;
	int lenDiff = abs(lenInput1 - lenInput2);
	int output = 0;

	// compare the lengths of the input strings, add leading zeros to adjust to the same length

	if (lenInput1 < lenInput2) {
		input1 = adjustStringLength(input1, lenDiff);
	}

	if (lenInput1 > lenInput2) {
		input2 = adjustStringLength(input2, lenDiff);
	}



	lenInput1 = input1.length();
	lenInput2 = input2.length();

	// calls function to add binary numbers together, saves to

	outputStrng = addNumbers(input1, input2);

	//compares length of output string to lengths of input strings, adds leading zeros to input strings to match length (this part is just to format the output and make things look nice)
	lenOutput = outputStrng.length();
	lenInput1 = input1.length();
	lenInput2 = input2.length();

	lenDiff = abs(lenInput1 - lenOutput);

	if (lenInput1 < lenOutput) {
		input1 = adjustStringLength(input1, lenDiff);
	}

	lenDiff = abs(lenInput2 - lenOutput);

	if (lenInput2 < lenOutput) {
		input2 = adjustStringLength(input2, lenDiff);
	}


	if (dispCalc == true) {

		// display the calculation in both binary and base 10

		cout << endl;
		cout << "    " << input1 << "                " << convertToBaseTen(input1) << endl;
		cout << "  + " << input2 << "              + " << convertToBaseTen(input2) << endl;
		cout << "----------------------------------------------------------------" << endl;
		cout << "    " << outputStrng << "                " << convertToBaseTen(outputStrng) << endl;

	}

	outputInt = stoi(outputStrng);

	if (dispCalc == false) {
		cout << outputInt;
	}

	return outputInt;


}


int main(){

	string input1 = "1011111";
	string input2 = "101011100";
	bool displayCalculation = true;


	calculate(input1, input2, displayCalculation);


	return 0;
}
