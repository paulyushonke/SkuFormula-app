#include <iostream>
#include <cmath>
#include <ctype.h>
#include <string>

using namespace std;
double calculation_y(double a, double b, int n, double step);
int comparing_a_b(double &a, double &b);
double request_input_til_valid_double(std::string arg_name);
int request_input_til_valid_int();
bool check_if_a_number(std::string a, double &x);
bool compare(std::string input, std::string finish_transformation);
string entering_value(std::string name_of_argument);
string convertation(std::string input, double &possible_argument);
int error_output(string input, double &n);

int main()
{

    double a;
    double b;
    int i = comparing_a_b(a, b);
    double step = request_input_til_valid_double("step");
    if (!(step > 0))
    {
        do
        {
            cout << "oops!step should be positive!";
            step = request_input_til_valid_double("step");
        } while (!(step > 0));
    }

    int n = request_input_til_valid_int();
    double y = calculation_y(a, b, n, step);
    return 0;
}

int comparing_a_b(double &a, double &b)
{
    a = request_input_til_valid_double("a");
    b = request_input_til_valid_double("b");
    if (a > b || a == b)
    {
        do
        {
            cout << "oops!a should be less than b!";
            a = request_input_til_valid_double("a");
            b = request_input_til_valid_double("b");
        } while (a > b || a == b);
        return 0;
    }
    return 0;
}

double request_input_til_valid_double(std::string arg_name)
{
    double arg;
    string input = entering_value(arg_name);
    if (!check_if_a_number(input, arg))
    {
        do
        {
            cout << "oops! " << arg_name << " should be a number:";
            cin >> input;
        } while (!check_if_a_number(input, arg));
    }
    return arg;
}

double calculation_y(double a, double b, int n, double step)
{
    int counter = 0;
    for (double x = a; x <= b; x += step)
    {
        counter++;
        if (x >= 0)
        {
            double y = 0;
            for (double i = 1; i <= n - 1; i++)
            {
                y += i;
            }
            cout << "x" << counter << " = " << x << " y" << counter << " = " << x - y << endl;
        }
        else if (x < 0)
        {
            double y = 0;
            double y_o = 0;
            for (int i = 1; i <= n - 1; i++)
            {
                y = 0;
                for (double j = 1; j <= n; j++)
                {
                    y += j / (pow(j, 2) + j);
                }
                y_o += y;
            }
            cout << "x" << counter << " = " << x << " y" << counter << " = " << y_o << endl;
        }
    }
    return 0;
}

int request_input_til_valid_int()
{
    double n;
    string input = entering_value("n");
    int error;
    do
    {
        error = error_output(input, n);
        if (error == 1)
        {
            cout << "oops! n should be an integer:";
            cin >> input;
        }
        if (error == 0)
        {
            return (int)n;
            break;
        }
        if (error == 2)
        {
            cout << "oops! n should be more than/equal to 2:";
            cin >> input;
        }
        if (error == 3)
        {
            cout << "oops! n should be a number:";
            cin >> input;
        }
    } while (!error == 0);
    return (int)n;
}

bool check_if_a_number(std::string a, double &x)
{

    if (isdigit(a[0]) || (a[0] == '-' && isdigit(a[1]))) // we shoul check the first char to avoid problems with stod()
    {
        string output = convertation(a, x);

        if (compare(a, output))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}

bool compare(std::string input, std::string finish_transformation)
{
    if (input == finish_transformation)
    {
        return true;
    }
    else
    {
        return false;
    }
}

string entering_value(std::string name_of_argument)
{
    string arg;
    cout << "enter " << name_of_argument << ":";
    cin >> arg;
    return arg;
}

string convertation(std::string input, double &possible_argument)
{
    possible_argument = stod(input);
    string result_of_transformation = to_string(possible_argument);
    result_of_transformation.erase(result_of_transformation.find_last_not_of('0') + 1, std::string::npos);
    result_of_transformation.erase(result_of_transformation.find_last_not_of('.') + 1, std::string::npos);
    return result_of_transformation;
}

int error_output(string input, double &n)
{
    if (check_if_a_number(input, n))
    {
        if (stoi(input) != stod(input))

        {
            return 1;
        }
        else if (!(stod(input) >= 2))
        {
            return 2;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        return 3;
    }
}