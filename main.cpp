#include <iostream>
#include <string>
using namespace std;

string answer;   // a b c d
int grade;      // sum of the weights of questions (out of 100%)

class Quiz {    // Class
private:        // Access Specifier
    string questionText;
    string op1, op2, op3, op4;
    string correct;
    int weight; //add these if correct to get total grade

public:
    // set and get function prototypes but for the class
    //            question   op1     op2     op3    op4     corr   question weight
    void set(string, string, string, string, string, string, int);
    void printQuestion();
};

int main()
{
    // ready/start
    string temp;
    cout << "\nWelcome!\nReady to start the quiz?\nyes/no" << endl;
    cin >> temp;
    if (temp == "yes" || temp == "y") {
        cout << "Starting Quiz" << endl;
    }
    else {
        cout << "Ending Quiz" << endl;
        return 0;
    }

    // object setting
    Quiz q1, q2, q3, q4;

    // corresponds to public class 'set' function
    // q.set("questionText", "op1", "op2", "op3", "op4", "correct input", "weight");
    q1.set("#1: What is 1 + 1? (15pts)","2","3","4","5", "a", 15);
    q2.set("#2: What is 2 * 4? (25pts)","4","8","16","32", "b", 25);
    q3.set("#3: What is 2^3? (30pts)","2","4","8","16", "c", 30);
    q4.set("#4: What is 100 % 2? (30pts)","3","2","1","0", "d", 30);

    // formatting into provided template (printQuestion()) using the values set above
    q1.printQuestion();
    q2.printQuestion();
    q3.printQuestion();
    q4.printQuestion();

    // AFTER TEST IS DONE vvv //

    cout << "Grade: " << grade << " / 100" << endl;
    if (grade >= 70)
        cout << "You passed! Good job!" << endl;
    else
        cout << "You failed. Try again!" << endl;

    return 0;
    //end of main()
}


// expanded prototypes outside of class
// simple set stuff to take from private to public
void Quiz::set(string q, string o1, string o2, string o3, string o4, string c, int w)
{
    questionText = q;
    op1 = o1;
    op2 = o2;
    op3 = o3;
    op4 = o4;
    correct = c;
    weight = w;
}

// printing
void Quiz::printQuestion()
{
    // print the questions
    cout << questionText << endl;
    cout << "a) " << op1 << endl;
    cout << "b) " << op2 << endl;
    cout << "c) " << op3 << endl;
    cout << "d) " << op4 << endl;

    // display the answer
    cout << "Type a single letter to answer." << endl;
    cin >> answer;

    // if correct, increment total grade by the weight of the question
    if (answer == correct) {
        cout << "Correct!" << endl;
        cout << "\n----------" << endl;
        grade += weight;
    }
    else { // don't
        cout << endl;
        cout << "Incorrect.\n" << endl;
    }
}