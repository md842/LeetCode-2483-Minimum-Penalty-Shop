/*
 * 2483. Minimum Penalty for a Shop
    https://leetcode.com/problems/minimum-penalty-for-a-shop/.

 * You are given the customer visit log of a shop represented by a 0-indexed
    string customers consisting only of characters 'N' and 'Y':

 *  if the ith character is 'Y', it means that customers come at the ith hour
 *  whereas 'N' indicates that no customers come at the ith hour.

 * If the shop closes at the jth hour (0 <= j <= n), the penalty is calculated
    as follows:

 *  For every hour when the shop is open and no customers come, the penalty
     increases by 1.
 *  For every hour when the shop is closed and customers come, the penalty
     increases by 1.

 * Return the earliest hour at which the shop must be closed to incur a minimum
    penalty.

 * Note that if a shop closes at the jth hour, it means the shop is closed at
    the hour j.
 
 * Constraints:
 *  1 <= customers.length <= 105
 *  customers consists only of characters 'Y' and 'N'.
 */

#include <iostream>
#include <iomanip> // This is used by test(), not the main algorithm
#include <string> // This is used by test(), not the main algorithm

using std::string;
using std::cout; // This is used by test(), not the main algorithm
using std::endl; // This is used by test(), not the main algorithm

int bestClosingTime(string customers){
  int penalty = 0;
  // First, calculate penalty if we closed at hour 0.
  for (int hour = 0; hour <= customers.length(); hour++){
    if (customers[hour] == 'Y') 
      penalty++; // Closed immediately, any hour with customers adds 1 penalty
  }
  int min = penalty;
  int minHour = 0;
  // Next, for each closing time, calculate how it would change the penalty.
  for (int closingTime = 1; closingTime <= customers.length(); closingTime++){
    if (customers[closingTime - 1] == 'Y') // Customers at previous hour
      penalty--; // Remove 1 penalty for staying open for hour with customers
    else // No customers at previous hour
      penalty++; // Add 1 penalty for staying open for hour with no customers
    if (penalty < min){ // If this is the new lowest penalty
      min = penalty; // Save the penalty value for future comparisons
      minHour = closingTime; // Save the current closing time to return
    }
  }
  return minHour; // Return minimum penalty
}

void test(string customers, int exp){
  string testCase = "customers: " + customers;

  int output = bestClosingTime(customers);
  string details = "Expected " + std::to_string(exp) + ", got " +\
                   std::to_string(output);

  string status = "";
  if (exp == output)
    status = "OK";
  else
    status = "Error";

  cout << std::setw(16) << testCase << std::setw(11) << status << std::setw(25)
  << details << endl;
}

int main(){
  // Test cases
  cout << endl << std::setw(16) << "Test case" << std::setw(11) << "Status";
  cout << std::setw(25) << "Details" << endl;
  cout << std::string(52, '-') << endl;

  test("YYNY", 2);
  test("NNNNN", 0);
  test("YYYY", 4);

  return 0;
}
