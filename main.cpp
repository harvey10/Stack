#include <iostream>

void printMenu(const Stack a) {
  a.print();
  cout << "Please make a selection:" << endl << "1. Push" << endl
  << "2. Pop" << endl << "3. Exit" << endl;
}

int getMenuChoice() {
  int menuChoice;
  bool done = false;
  while (!done) {
    try {
      cout << "Selection: ";
      cin >> menuChoice;
      if (!cin || menuChoice < 1 || menuChoice > 3)
        throw menuChoice;
      else {
        return menuChoice;
      }
    }
    catch (int menuChoice) {
      cout << "Enter choice between 1 and 3 : ";
    }
    catch(...) {
      cout << "Enter choice between 1 and 3 : ";
      cin.clear();
      cin.ignore(100,'\n');
    }
  }
}

int main() {
  Stack s;
  int menuChoice;
  int pushElement

  while (menuChoice != 3) {
    printMenu(s);
    menuChoice = getMenuChoice();
    if (menuChoice == 1) {
      cout << "Enter element to push: ";
      try {
        cin >> pushElement;
        if (!cin)
          throw;
        else
          s.push(pushElement);
      }
      catch(...) {
        cin.clear();
        cin.ignore(100, '\n');
        cout << "Not acceptable element to push." << endl;
        menuChoice = NULL;
      }
    }

    else if (menuChoice == 2) {
      cout << s.pop() << " was removed from the stack" << endl;
    }

    else {
      return 0;
    }
  }
}
