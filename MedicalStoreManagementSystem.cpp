#include <iostream>
#include <windows.h>
#include <conio.h>
#include <string>
#include <fstream>
using namespace std;
void header();                                                    // to print header
bool signUP();                                                    // to sign up new user
string signIN();                                                  // to sign in new user
void clearscreen();                                               // to clearscreen
void storeInFileUsers();                                          // will store users in file
void storeInFilePerchasingDetail();                               // will store perchase detail of customers in file
void storeInventoryInFile();                                      // will store  inventiry in files
void readUsersfromFile();                                         // will read users from file
void readFromFilePerchasingDetail();                              // will allow admin to see  perchasing detail
string parseRecord(string record, int field);                     // will parse record extracted from file
string parseRecordforPerchasingDetails(string record, int field); // will parse record for perchasing details
bool checkUsersInArray(string username, string userpassword, string role);
bool validUserName(string userName);                                                   // will validate username
bool checkComa(string parameter);                                                      // will check commas in strings
bool checkpwd(string userpassword, int length);                                        // validation to check password
bool hasdigit(string userpassword, int length);                                        // validation to check password
bool hasuppercase(string userpassword, int length);                                    // validation to check password
bool haslowercase(string password, int length);                                        // validation to check password
bool validRole(string role);                                                           // validation to check role
bool checkPrice(string mPrice);                                                        // validation check price if it is in numbers
int loginView();                                                                       // for login
int AdminMainScreen();                                                                 // will view admin options
int customerMainScreen();                                                              // will view customer options
void createList();                                                                     // admin will create list
bool checkMedicineInArray(string mName);                                               // will check presence of medicine in array
void sortData();                                                                       // will allow admin to sort data according to their prices
void updatelist();                                                                     // admin can update his list
void checkFeedback();                                                                  // will allow admin to check feedback of customer
void checklist();                                                                      // admin will check his stocks
void discount();                                                                       // to give discount to customer
void checkValidationsOnDiscount(string giveDiscountOnPrice, string availableDiscount); // to check validations on discount
void addToCart();                                                                      // will allow customer to add med to cart
void storeSelectedMedInArray(int i, int j, string mName);                              // will store medicine that are added to cart in array
void unselectItemsFromCart();                                                          // will allow customer to remove medicines from cart
int checkInArrayToRemoveFromCart();                                                    // customer will be able to remove items from cart
int checkinArraytoDeleteitem();                                                        // will check item is available in array or not
void deleteitems();                                                                    // for admin to delete items from list
void Addcustomer();                                                                    // for admin to add customers
void updateprice(string mName, int updatedprice);                                      // for admin to update price in list
void updatedPriceName();                                                               // will take name of medicine whose price you want to update
void customerdetail();                                                                 // admin can see his customers
void showlist();                                                                       // will show list to customer
void readInventoryDetailsFromFiles();                                                  // will read items store in file
void checkCart();                                                                      // customer will check his cart
void removeCart();                                                                     // will remove cart
void payBill();                                                                        // customer can pay bill
void checkDiscount(int convertedAmountToPay);                                          // will calculate price after discount
void giveFeedback();                                                                   // will allow customer to give feedback
const int userarrsize = 100;                                                           // costant array size
string users[userarrsize];                                                             // array for storing users of application
string password[userarrsize];                                                          // array for storing users password
string roles[userarrsize];                                                             // array for storing users roles
int usercount = 0;                                                                     // it will take a count users
int medicinestock[userarrsize];                                                        // store the info of stock available in store
int medicineprice[userarrsize];                                                        // store the medicines prices in store
string medicinename[userarrsize];                                                      // store medicines names
int medicinecount = 0;                                                                 // take a count of medicines in store
string selectedmedicines[userarrsize];                                                 // will store medicines name selected by user
int selectedmedicineprice[userarrsize];                                                // will store medicines prices selected by user
int selectedmedicinecount = 0;                                                         // will take a count of medicines selected by customer
int quantity[userarrsize];                                                             // will store quantity of medicine that user wantrs to buy
string feedBack[userarrsize];                                                          // will allow customers to give feedback
int length;                                                                            // to store length of entered password
int totalprice = 0;
int convertedGiveDiscountOnPrice; // to show above which price discount is available
int convertedAvailableDiscount;   // to store offered discount
int feedbackCounter = 0;
main()
{
    readUsersfromFile();
    readInventoryDetailsFromFiles();
    int checkADMS;    // will check options entered by admins
    int checkCMS;     // will check options entered by customer
    string checkrole; // will check role of users
    int choice;       // will check login choices from login menu
    header();
    while (choice != 3) // loop for login
    {
        choice = loginView();
        if (choice == 1) // choice 1 is for admin
        {
            system("cls");
            header();
            checkrole = signIN();
            if (checkrole == "admin" || checkrole == "Admin")
            {
                while (checkADMS != 12) // loop for checking admin options
                {
                    checkADMS = AdminMainScreen();
                    if (checkADMS == 1)
                    {
                        checklist();
                    }
                    else if (checkADMS == 2)
                    {
                        updatelist();
                        storeInventoryInFile();
                    }
                    else if (checkADMS == 3)
                    {
                        Addcustomer();
                        signUP();
                        storeInFileUsers();
                    }
                    else if (checkADMS == 4)
                    {
                        deleteitems();
                        storeInventoryInFile();
                        clearscreen();
                    }
                    else if (checkADMS == 5)
                    {
                        updatedPriceName();
                        storeInventoryInFile();
                    }
                    else if (checkADMS == 6)
                    {
                        customerdetail();
                    }
                    else if (checkADMS == 7)
                    {
                        checkFeedback();
                        clearscreen();
                    }
                    else if (checkADMS == 8)
                    {
                        discount();
                    }
                    else if (checkADMS == 9)
                    {
                        createList();
                        storeInventoryInFile();
                        clearscreen();
                    }
                    else if (checkADMS == 10)
                    {
                        sortData();
                        storeInventoryInFile();
                        clearscreen();
                    }
                    else if (checkADMS == 11)
                    {
                        system("cls");
                        header();
                        readFromFilePerchasingDetail();
                        clearscreen();
                    }
                    else if (checkADMS == 12)
                    {
                        clearscreen();
                    }
                }
            }
            else if (checkrole == "customer" || checkrole == "Customer")
            {
                checkCMS = 0;
                while (checkCMS != 7) // loop for checking customer option
                {
                    checkCMS = customerMainScreen();
                    if (checkCMS == 1)
                    {
                        showlist();
                    }
                    else if (checkCMS == 2)
                    {
                        addToCart();
                    }
                    else if (checkCMS == 3)
                    {
                        checkCart();
                        clearscreen();
                    }
                    else if (checkCMS == 4)
                    {
                        unselectItemsFromCart();
                    }
                    else if (checkCMS == 5)
                    {
                        payBill();
                        clearscreen();
                        storeInFilePerchasingDetail();
                        removeCart();
                        // totalprice = 0;
                        clearscreen();
                    }
                    else if (checkCMS == 6)
                    {
                        giveFeedback();
                        clearscreen();
                    }
                    else if (checkCMS == 7)
                    {
                        clearscreen;
                    }
                }
            }
        }

        else if (choice == 2) // choice 2 is for signup
        {
            system("cls");
            header();
            bool isvalid = signUP();
            if (isvalid)
            {
                cout << "SignedUp Successfully!" << endl;
                storeInFileUsers();
            }
            if (isvalid = false)
            {
                cout << "TRY AGAIN!!" << endl;
            }
        }
        else if (choice == 3)
        {
            cout << "Wrong Input!" << endl;
        }
        clearscreen();
    }
}
void header() // to print header
{
    cout << "'##::::'##:'########:'########::'####::'######:::::'###::::'##:::::::::::'######::'########::'#######::'########::'########::::" << endl;
    cout << " ###::'###: ##.....:: ##.... ##:. ##::'##... ##:::'## ##::: ##::::::::::'##... ##:... ##..::'##.... ##: ##.... ##: ##.....:::::" << endl;
    cout << " ####'####: ##::::::: ##:::: ##:: ##:: ##:::..:::'##:. ##:: ##:::::::::: ##:::..::::: ##:::: ##:::: ##: ##:::: ##: ##::::::::::" << endl;
    cout << " ## ### ##: ######::: ##:::: ##:: ##:: ##:::::::'##:::. ##: ##::::::::::. ######::::: ##:::: ##:::: ##: ########:: ######::::::" << endl;
    cout << " ##. #: ##: ##...:::: ##:::: ##:: ##:: ##::::::: #########: ##:::::::::::..... ##:::: ##:::: ##:::: ##: ##.. ##::: ##...:::::::" << endl;
    cout << " ##:.:: ##: ##::::::: ##:::: ##:: ##:: ##::: ##: ##.... ##: ##::::::::::'##::: ##:::: ##:::: ##:::: ##: ##::. ##:: ##::::::::::" << endl;
    cout << " ##:::: ##: ########: ########::'####:. ######:: ##:::: ##: ########::::. ######::::: ##::::. #######:: ##:::. ##: ########::::" << endl;
    cout << "..:::::..::........::........:::....:::......:::..:::::..::........::::::......::::::..::::::.......:::..:::::..::........:::::" << endl;
}
int loginView() // for login
{
    bool isvalid;
    system("cls");
    header();
    string choice; // choice is used to store the input entered by user
    int convertedChoice;
    cout << "Enter choice" << endl;
    cout << "1.sign in" << endl;
    cout << "2.sign up:" << endl;
    cout << "Enter key:" << endl;
    while (true)
    {
        cin >> choice;
        isvalid = checkPrice(choice);
        convertedChoice = atoi(choice.c_str());
        if (convertedChoice <= 2)
        {
            return convertedChoice;
            break;
        }
        else
        {
            cout << "You entered an invalid input" << endl;
        }
    }
}
bool signUP()
{
    int count = 0;
    bool isValiduserName, isValidPassword, isValidRole;
    bool checkUserNameComma, checkPasswordComa;
    string userName;     // to store name entered by user
    string userpassword; // to store password enteres by user
    string userrole;     // to store role entered by user
    while (true)
    {
        cout << "enter name" << endl;
        getline(cin >> ws, userName);
        isValiduserName = validUserName(userName);
        checkUserNameComma = checkComa(userName); // will check comma in username
        if (checkUserNameComma)
        {
            if (isValiduserName)
            {
                users[usercount] = userName; // will store username in array of users
                count++;
                break;
            }
        }
    }
    while (true)
    {
        cout << "enter password" << endl;
        getline(cin >> ws, userpassword);
        int length = userpassword.length();
        isValidPassword = checkpwd(userpassword, length);
        checkPasswordComa = checkComa(userpassword); // will check comma in password
        if (checkPasswordComa)
        {
            if (isValidPassword)
            {
                password[usercount] = userpassword; // will store users password in aary of password
                count++;
                break;
            }
            else
            {
                cout << "Wrong Password!" << endl
                     << "pasword length must be eight";
                cout << " and contain an uppercase and lowercase letter and a digit" << endl;
                ;
            }
        }
    }
    while (true)
    {
        cout << "enter role:";
        getline(cin >> ws, userrole);
        isValidRole = validRole(userrole);
        if (isValidRole)
        {
            roles[usercount] = userrole; // will store roles  of users in array of roles
            count++;
            break;
        }
    }
    if (count == 3)
    {
        usercount++;
        return true;
    }
    else
    {
        return false;
    }
}
void storeInFileUsers() // store users in file
{
    fstream writeUsersFile;
    writeUsersFile.open("UsersFile.txt", ios::app);
    writeUsersFile << users[usercount - 1] << "," << password[usercount - 1] << "," << roles[usercount - 1] << endl;
    writeUsersFile.close();
}
string signIN() // for sign in
{
    bool checkUser;          // will check presence of user
    string username;         // will store name entered by user
    string userpassword;     // will store password entered by user
    string role, returnrole; // will store role enter by user

    cout << "enter name";
    getline(cin >> ws, username);
    cout << "enter password";
    getline(cin >> ws, userpassword);
    cout << "Enter role" << endl;
    getline(cin >> ws, role);
    checkUser = checkUsersInArray(username, userpassword, role);

    if (checkUser == true)
    {
        returnrole = role;
    }
    else if (checkUser == false)
    {
        cout << " You entered wrong information!" << endl;
    }
    return returnrole;
}
bool checkUsersInArray(string username, string userpassword, string role)
{
    for (int i = 0; i < usercount; i++) // loop for identifying users
    {
        if (users[i] == username && password[i] == userpassword && role == roles[i])
        {
            return true;
        }
    }

    return false;
}
void readUsersfromFile() // to read users from file
{
    string word;
    fstream f_variable;
    f_variable.open("UsersFile.txt", ios::in);
    int count = 0;
    while (!(f_variable.eof()))
    {
        getline(f_variable, word);
        if (word == "")
        {
            continue;
        }

        users[count] = parseRecord(word, 1);
        password[count] = parseRecord(word, 2);
        roles[count] = parseRecord(word, 3);
        count++;
    }
    usercount = count;
    f_variable.close();
}
string parseRecord(string record, int field) // parse record for storing in array
{
    int commaCount = 1;
    string item;
    for (int i = 0; i < record.length(); i++)
    {
        if (record[i] == ',')
        {
            commaCount = commaCount + 1;
        }
        else if (commaCount == field)
        {
            item = item + record[i];
        }
    }
    return item;
}
int AdminMainScreen() // will view admin options
{
    system("cls");
    header();
    string key;
    bool isvalid;
    int convertedKey;
    cout << "***********ADMIN MAIN SCREEN**********" << endl;
    cout << "1.Check list" << endl;
    cout << "2.Update list" << endl;
    cout << "3.Add customer" << endl;
    cout << "4.Delete items" << endl;
    cout << "5.Update prices" << endl;
    cout << "6.View customer details" << endl;
    cout << "7.Check feedback" << endl;
    cout << "8.Discount" << endl;
    cout << "9.Create list" << endl;
    cout << "10.Sort data accordingly" << endl;
    cout << "11.Customer details" << endl;
    cout << "12.Log out" << endl;
    while (true)
    {
        getline(cin >> ws, key);
        isvalid = checkPrice(key);
        convertedKey = atoi(key.c_str());
        if (convertedKey <= 12)
        {
            return convertedKey;
            break;
        }
        else
        {
            cout << "You entered invalid input" << endl;
        }
    }
}
int customerMainScreen() // will view customer options
{
    bool isvalid;
    system("cls");
    header();
    cout << "***************CUSTOMER MAIN SCREEN**************" << endl;
    int convertedKey;
    string key;
    cout << "1.Show List " << endl;
    cout << "2.Add to Cart" << endl;
    cout << "3.Check Cart" << endl;
    cout << "4.Unselect Items" << endl;
    cout << "5.Pay Bill" << endl;
    cout << "6.Give Feedback" << endl;
    cout << "7.Log Out" << endl;
    cout << "Enter Choice";
    while (true)
    {
        cin >> key;
        isvalid = checkPrice(key);
        convertedKey = atoi(key.c_str());
        if (convertedKey <= 7)
        {
            return convertedKey;
            break;
        }
        else
        {
            cout << "You entered invalid input" << endl;
        }
    }
}
void readInventoryDetailsFromFiles() // will read items store in file
{
    string word;
    string nameOfMedicine;
    string priceOfMedicine;
    string stockOfMedicine;
    int convertedPriceOfMedicine;
    int convertedStockOfMedicine;

    fstream f_variable;
    f_variable.open("inventoryDetails.txt", ios::in);
    int count = 0;
    while (!(f_variable.eof()))
    {
        getline(f_variable, word);
        if (word == "")
        {
            break;
        }
        nameOfMedicine = parseRecord(word, 1);
        priceOfMedicine = parseRecord(word, 2);
        convertedPriceOfMedicine = atoi(priceOfMedicine.c_str());
        stockOfMedicine = parseRecord(word, 3);
        convertedStockOfMedicine = atoi(stockOfMedicine.c_str());
        // will store in array
        medicinename[count] = nameOfMedicine;
        medicineprice[count] = convertedPriceOfMedicine;
        medicinestock[count] = convertedStockOfMedicine;
        count++;
    }
    medicinecount = count;
    f_variable.close();
}
void createList() // admin will create list
{
    int convertedNoOfItems, convertedPrice, convertedStock;

    bool isvalidNoOfItem, isValidMname, isValidPrice, isValidStock, ispresent;
    string noOfItems;
    string mName;
    string mPrice;
    string mStock;
    cout << "Enter number of items you want to add:" << endl;
    getline(cin >> ws, noOfItems);

    isvalidNoOfItem = checkPrice(noOfItems);

    if (isvalidNoOfItem)
    {
        convertedNoOfItems = atoi(noOfItems.c_str());
        for (int i = 0; i < convertedNoOfItems; i++)
        {
            cout << "Enter name of medicine:" << endl;
            getline(cin >> ws, mName);
            // check validation
            isValidMname = checkComa(mName);
            ispresent = checkMedicineInArray(mName);
            if (ispresent)
            {
                while (true)
                {
                    cout << "Enter price of medicine:" << endl;
                    getline(cin >> ws, mPrice);
                    isValidPrice = checkPrice(mPrice);
                    if (isValidPrice)
                    {
                        break;
                    }
                }
                while (true)
                {
                    cout << "Enter stock you want to enter:" << endl;
                    getline(cin >> ws, mStock);
                    isValidStock = checkPrice(mStock);
                    if (isValidStock)
                    {
                        break;
                    }
                }
                // to store medicines in array
                if (isValidMname && isValidPrice && isValidStock)
                {
                    convertedPrice = atoi(mPrice.c_str());
                    convertedStock = atoi(mStock.c_str());
                    medicinename[medicinecount] = mName;
                    medicineprice[medicinecount] = convertedPrice;
                    medicinestock[medicinecount] = convertedStock;
                    medicinecount++;
                }
            }
        }
    }
}
bool checkMedicineInArray(string mName) // will check presence of medicines in array
{
    bool flag = true;
    for (int i = 0; i < medicinecount; i++)
    {
        if (medicinename[i] == mName)
        {
            flag = false;
            cout << "Already Present" << endl;
        }
    }
    return flag;
}
void checklist() // admin will check his stocks
{
    cout << "*****************LIST*******************" << endl;
    cout << "\tMEDICINE NAME\t\tPRICE\t\t<<STOCK" << endl;

    for (int i = 0; i < medicinecount; i++) // loop tp print medicie names quantity and stock
    {
        cout << "\t\t" << medicinename[i] << "\t\t" << medicineprice[i] << "\t\t" << medicinestock[i] << endl;
    }
    clearscreen();
}
void updatelist() // admin can update his list
{
    system("cls");
    header();
    cout << "********************UPDATE MENUE********************" << endl;
    string mName; // to store name of medicine admin want to update in list
    bool comaInName, comaInPrice, comaInStock, validPrice, validStock, ispresent;
    int count = 0;
    string mStock, mPrice;              // to store price of medicine admin want to update in list
    int convertedStock, convertedPrice; // to store stock of medicine stock admin want to update in list

    cout << "enter medicine name";
    getline(cin >> ws, mName);

    ispresent = checkMedicineInArray(mName);
    if (ispresent)
    {
        comaInName = checkComa(mName);
        while (true)
        {
            cout << "Enter medicine price";
            getline(cin >> ws, mPrice);
            validPrice = checkPrice(mPrice);
            if (validPrice)
            {
                break;
            }
        }
        while (true)
        {
            cout << "Enter stock you want to enter";
            getline(cin >> ws, mStock);
            validStock = checkPrice(mStock);
            if (validStock)
            {
                break;
            }
        }
        if (comaInName && validPrice && validStock)
        {
            medicinename[medicinecount] = mName; // will store new medicine name in list
            convertedPrice = atoi(mPrice.c_str());
            medicineprice[medicinecount] = convertedPrice; // will store price of new medicine
            convertedStock = atoi(mStock.c_str());
            medicinestock[medicinecount] = convertedStock; // will store stock of new medicine
            medicinecount++;
        }
    }
    clearscreen();
}
void storeInventoryInFile() // will store inventory in file
{
    fstream writeMedicineFile;
    writeMedicineFile.open("inventoryDetails.txt", ios::out);
    // loop to store inventory in file
    for (int i = 0; i < medicinecount; i++)
    {
        writeMedicineFile << medicinename[i] << "," << medicineprice[i] << "," << medicinestock[i] << endl;
    }
    writeMedicineFile.close();
}
void Addcustomer() // admin can add customers
{
    system("cls");
    header();
    cout << "**************ADD CUSTOMERS**************" << endl;
}
void deleteitems() // admin can delete items from his list
{
    system("cls");
    header();
    cout << "**************************DELETE ITEMS********************" << endl;
    int index = 0;
    index = checkinArraytoDeleteitem();
    if (index != -1)
    {
        for (int i = index; i < medicinecount; i++) // loop to delete item and store other itens at that place
        {
            medicinename[i] = medicinename[i + 1];
            medicineprice[i] = medicineprice[i + 1];
            medicinestock[i] = medicinestock[i + 1];
        }
        medicinecount--;
    }
    else
    {
        cout << "You entered wrong medicine name!" << endl;
    }
}
int checkinArraytoDeleteitem()
{
    string mName; // to store name of medicine admin wants to delete
    cout << "enter medicine name you want to delete:";
    getline(cin >> ws, mName);
    bool flag = false;                      // to identify medicine in list
    int index = -1;                         // to store array index where medicine name is found
    for (int i = 0; i < medicinecount; i++) // loop to check presence of medicine
    {
        if (medicinename[i] == mName)
        {
            index = i;
            cout << "press any key to confirm deletion!!" << endl;
            getch();
        }
    }
    return index;
}
void updatedPriceName() // will take name of medicine whose price you want to update
{
    system("cls");
    header();
    cout << "*****************UPDATE PRICE MENU********************" << endl;
    bool isValidName, isValidPrice;
    int convertedUpdatedPrice; // will store int updated price
    string mName;              // to stotre na,me of medicine you want to update price
    string updatedprice;       // will store updated price of medicine

    cout << "enter medicine name whose price you want to update.." << endl;
    getline(cin >> ws, mName);
    // will check validation on name
    isValidName = checkComa(mName);
    cout << "Enter Updated Price " << endl;
    getline(cin >> ws, updatedprice);
    // will check validation on price
    isValidPrice = checkPrice(updatedprice);
    if (isValidPrice && isValidName)
    {
        convertedUpdatedPrice = atoi(updatedprice.c_str());
        updateprice(mName, convertedUpdatedPrice);
    }
}
void updateprice(string mName, int convertedUpdatedPrice)
{
    int count = 0;
    for (int i = 0; i < medicinecount; i++) // loop to check medicine in list
    {
        if (medicinename[i] == mName)
        {
            count++;
            medicineprice[i] = convertedUpdatedPrice;
        }
    }
    if (count == 0)
    {
        cout << "Medicine is not in list!" << endl;
        getch();
    }
}
void customerdetail() // admin can see his customers
{
    system("cls");
    header();
    for (int i = 0; i < usercount; i++)
    {
        if (roles[i] == "customer" || "Customer")
        {
            cout << users[i] << endl;
            cout << password[i] << endl;
        }
        clearscreen();
    }
}
void discount()
{
    string giveDiscountOnPrice, availableDiscount; // variable to store discount and price

    cout << "ENTER DISCOUNT YOU WANT TO GIVE!" << endl;
    getline(cin >> ws, availableDiscount);

    cout << "ENTER AMOUNT ABOVE WHICH YOU WANT TO GIVE DISCOUNT: " << endl;
    getline(cin >> ws, giveDiscountOnPrice);
    // will check validations on discount
    checkValidationsOnDiscount(giveDiscountOnPrice, availableDiscount);
}
void checkValidationsOnDiscount(string giveDiscountOnPrice, string availableDiscount) // will check validation on discount
{
    bool isValidGiveDiscountOnPrice, isValidAvailableDiscount;

    isValidGiveDiscountOnPrice = checkPrice(giveDiscountOnPrice);
    isValidAvailableDiscount = checkPrice(availableDiscount);

    if (isValidGiveDiscountOnPrice && isValidAvailableDiscount)
    {
        convertedGiveDiscountOnPrice = atoi(giveDiscountOnPrice.c_str());
        convertedAvailableDiscount = atoi(availableDiscount.c_str());
    }
}
void checkFeedback() // admin can check feedback of current customer
{
    cout << "customer name\tfeedback" << endl;
    cout << users[usercount - 1];
    cout << "\t";
    cout << feedBack[feedbackCounter - 1];
}
void sortData() // will sort data according to prices in ascending order
{
    int tempPrice, tempStock; // to store data temporarily
    string tempName;
    for (int i = 0; i < medicinecount; i++)
    {
        for (int j = i + 1; j < medicinecount; j++)
        {
            if (medicineprice[i] > medicineprice[j])
            {
                // swaping
                tempPrice = medicineprice[i];
                tempName = medicinename[i];
                tempStock = medicinestock[i];
                medicineprice[i] = medicineprice[j];
                medicinename[i] = medicinename[j];
                medicinestock[i] = medicinestock[j];
                medicineprice[j] = tempPrice;
                medicinename[j] = tempName;
                medicinestock[j] = tempStock;
            }
        }
    }
}
void showlist() // will show list to customer
{
    system("cls");
    header();
    cout << "***********************LIST OF MEDICINES*********************" << endl;
    cout << "\t\tMedicine Name\t\tPrice\t\t" << endl;
    for (int i = 0; i < medicinecount; i++)
    {
        cout << "\t\t" << medicinename[i] << "\t\t" << medicineprice[i] << endl;
    }
    clearscreen();
}
void addToCart() // customer can add medicines to cart
{
    system("cls");
    header();
    cout << "*****************ADD TO CART****************" << endl;
    string numberOfMedicine;           // will store amount of medicine
    string mName;                      // name of medicine customer add to cart
    bool isValidNoOfMed, flag = false; // to take price in integer
    int convertedNoofMed;              // will store int no of medicines
    if (selectedmedicinecount > 0)
    {
        cout << " Empty the cart first!" << endl;
        getch();
    }
    else
    {
        while (true)
        {
            cout << "Enter amount of medicine: ";
            getline(cin >> ws, numberOfMedicine);

            isValidNoOfMed = checkPrice(numberOfMedicine);
            if (isValidNoOfMed)
            {
                convertedNoofMed = atoi(numberOfMedicine.c_str());
                break;
            }
        }
        for (int i = 0; i < convertedNoofMed; i++)
        {
            cout << "Enter Medicine Name:";
            getline(cin >> ws, mName);
            for (int j = 0; j < medicinecount; j++) // loop to check presence of desired medicine
            {
                if (medicinename[j] == mName)
                {
                    flag = true;
                    storeSelectedMedInArray(i, j, mName);
                }
            }
        }
        if (flag == false)
        {
            cout << "Medicine is not in List!" << endl;
            getch();
        }
        clearscreen();
    }
}
void storeSelectedMedInArray(int i, int j, string mName)
{
    bool isvalid;
    int mPrice; // will tell price to customer of that item
    int convertedQuantityToBuy;
    string quantityToBuy; // no of items customer wants to buy

    cout << "Enter Quantity:";
    getline(cin >> ws, quantityToBuy);
    isvalid = checkPrice(quantityToBuy);

    convertedQuantityToBuy = atoi(quantityToBuy.c_str());

    if (convertedQuantityToBuy > medicinestock[j])
    {
        cout << "NO more medicine is available" << endl;
    }
    else
    {
        // will store selected medicines in array
        quantity[selectedmedicinecount] = convertedQuantityToBuy;
        mPrice = medicineprice[j];
        selectedmedicineprice[selectedmedicinecount] = mPrice * convertedQuantityToBuy;
        selectedmedicines[selectedmedicinecount] = mName;
        selectedmedicinecount++; // will increase the counter of selected medicine by 1
        // will store total bill of customer
        medicinestock[j] = medicinestock[j] - convertedQuantityToBuy;
        totalprice = totalprice + selectedmedicineprice[i];
    }
}
void checkCart() // customer will check his cart
{
    system("cls");
    header();
    cout << "*********************YOUR CART********************" << endl;
    cout << "\t\tmedicines\tquantitiy\tprice" << endl;
    // loop
    for (int i = 0; i < selectedmedicinecount; i++)
    {
        cout << "\t\t" << selectedmedicines[i] << "\t\t" << quantity[i] << "\t\t" << selectedmedicineprice[i] << endl;
    }
}
void payBill()
{
    system("cls");
    header();
    bool isValid;
    string amountToPay;       // to store amount that user have
    int convertedAmountToPay; // to store payble amount after discount
    cout << "**********************YOUR BILL******************" << endl;
    checkCart();
    cout << "YOUR TOTAL BILL IS: " << totalprice << endl;
    if (totalprice > 0)
    {
        cout << "ENTER AMOUNT TO PAY: " << endl;
        getline(cin >> ws, amountToPay);
        isValid = checkPrice(amountToPay);
        if (isValid)
        {
            convertedAmountToPay = atoi(amountToPay.c_str());
            checkDiscount(convertedAmountToPay);
        }
    }
}

void checkDiscount(int convertedAmountToPay)
{
    int discounted;
    int change; // use to store customer extra price
    if (totalprice > convertedGiveDiscountOnPrice)
    {
        discounted = totalprice - ((totalprice * (convertedAvailableDiscount)) / 100);

        if (convertedGiveDiscountOnPrice > 0)
        {
            cout << "Your bill after discount is:" << discounted << endl;
        }
        if (convertedAmountToPay > discounted)
        {
            change = convertedAmountToPay - discounted;
            cout << "your change is:" << change << endl;
        }
        else if (convertedAmountToPay < discounted)
        {
            cout << "YOU HAVE LESS MONEY!!!" << endl;
        }
    }
    else if (totalprice < convertedGiveDiscountOnPrice)
    {
        if (convertedAmountToPay > totalprice)
        {
            change = convertedAmountToPay - totalprice;
            cout << "your change is:" << change << endl;
        }
        else if (convertedAmountToPay < totalprice)
        {
            cout << "YOU HAVE LESS MONEY!!!" << endl;
        }
    }
    cout << "WISH YOU HEALING AND PEACE!!" << endl;
    totalprice = 0;
}
void giveFeedback()
{
    string feedback;
    cout << "Enter your feedback:";
    getline(cin >> ws, feedback);
    feedBack[feedbackCounter] = feedback;
    feedbackCounter++;
}

void storeInFilePerchasingDetail()
{
    fstream writeUsersFile;
    writeUsersFile.open("perchasingdetails.txt", ios::app);
    for (int i = 0; i < selectedmedicinecount; i++)
    {
        cout << users[usercount - 1];
        writeUsersFile << users[usercount - 1] << "," << roles[usercount - 1] << "," << selectedmedicines[i] << "," << quantity[i] << "," << selectedmedicineprice[i] << endl;
    }
    writeUsersFile.close();
}
void readFromFilePerchasingDetail()
{
    string word;
    string nameOfMedicine, customername, role;
    string priceOfMedicine;
    string quantityofmed, feedback;
    fstream f_variable;
    f_variable.open("perchasingdetails.txt", ios::in);
    int count = 0;
    cout << "Customer Name\tmedicine name\tquantity\ttotalbill" << endl;
    while (!(f_variable.eof()))
    {
        getline(f_variable, word);
        if (word == "")
        {
            continue;
        }

        customername = parseRecordforPerchasingDetails(word, 1);
        role = parseRecordforPerchasingDetails(word, 2);
        nameOfMedicine = parseRecordforPerchasingDetails(word, 3);
        priceOfMedicine = parseRecordforPerchasingDetails(word, 4);
        quantityofmed = parseRecordforPerchasingDetails(word, 5);
        cout << customername << "\t\t" << nameOfMedicine << "\t\t" << priceOfMedicine << "\t\t" << quantityofmed << "\t\t" << endl;
    }
    f_variable.close();
}
string parseRecordforPerchasingDetails(string record, int field)
{
    int commaCount = 1;
    string item;
    for (int i = 0; i < record.length(); i++)
    {
        if (record[i] == ',')
        {
            commaCount = commaCount + 1;
        }
        else if (commaCount == field)
        {
            item = item + record[i];
        }
    }
    return item;
}
void removeCart() // will remove cart
{
    system("cls");
    header();

    {
        for (int i = 0; i <= selectedmedicinecount; i++) // loop to delete item and store other itens at that place
        {
            selectedmedicines[i] = "";
            quantity[i] = 0;
            selectedmedicineprice[i] = 0;
            selectedmedicinecount--;
        }
    }
}

void unselectItemsFromCart() // customer can unselect items from his order
{
    system("cls");
    header();
    int index = 0;
    index = checkInArrayToRemoveFromCart();
    if (index != -1)
    {
        for (int i = index; i < selectedmedicinecount; i++) // loop to delete item and store other itens at that place
        {
            selectedmedicines[i] = selectedmedicines[i + 1];
            selectedmedicineprice[i] = selectedmedicineprice[i + 1];
        }
        selectedmedicinecount--;
    }
    else
    {
        cout << "You entered wrong medicine name!" << endl;
    }
}

int checkInArrayToRemoveFromCart()
{
    string mName; // to store name of medicine admin wants to delete
    cout << "enter medicine name you want to remove from cart:";
    getline(cin >> ws, mName);
    int index = -1;                                 // to store array index where medicine name is found
    for (int i = 0; i < selectedmedicinecount; i++) // loop to check presence of medicine
    {
        if (selectedmedicines[i] == mName)
        {
            index = i;
            cout << "press any key to confirm !!" << endl;
            getch();
        }
    }
    return index;
}

bool validUserName(string userName) // validation to check username in array
{
    bool ispresent = true;
    for (int i = 0; i < usercount; i++) // loop for checking presence of user
    {
        if (users[i] == userName)
        {
            ispresent = false;
            break;
        }
    }
    if (ispresent == false)
    {
        cout << "user already present" << endl;
        return 0;
    }
    return ispresent;
}
bool checkComa(string parameter) // vallidation to check coma in input
{
    bool istrue = true;
    for (int i = 0; parameter[i] != '\0'; i++)
    {
        if (parameter[i] == ',')
        {
            istrue = false;
            cout << "Comma is not allowed!" << endl;
            break;
        }
    }
    return istrue;
}
bool checkPrice(string mPrice) // will check price if it is in numbers
{
    bool istrue = false;
    int count = 0;
    for (int i = 0; i <= mPrice.length(); i++)
    {
        if (mPrice[i] >= 48 && mPrice[i] <= 57)
        {
            count++;
        }
    }
    if (count == mPrice.length())
    {
        istrue = true;
        return istrue;
    }
    else
    {
        cout << "Enter Valid Information!" << endl;
        getch();
        return istrue;
    }
}

bool checkpwd(string password, int length) // validation to check password
{
    bool isvalid;
    isvalid = false;
    if (length >= 8)
    {
        bool ispresentD, ispresentUC, ispresentLC;
        ispresentD = hasdigit(password, length);
        ispresentUC = hasuppercase(password, length);
        ispresentLC = haslowercase(password, length);

        if (ispresentD && ispresentUC && ispresentLC)
        {
            return isvalid = true;
        }
    }
    else
        return isvalid;
}
bool hasdigit(string userpassword, int length)
{
    bool istrue = false;
    int counter = 0;
    for (int i = 0; i <= length; i++)
    {
        if (userpassword[i] >= 48 && userpassword[i] <= 122)
        {
            counter++;
        }
    }
    if (counter > 0)
    {
        istrue = true;
        return istrue;
    }
    else
    {
        return istrue;
    }
}
bool hasuppercase(string userpassword, int length)
{
    bool istrue = false;
    int counter = 0;
    for (int i = 0; i <= length; i++)
    {
        if ((userpassword[i] >= 65) && (userpassword[i] <= 90))
        {
            counter++;
        }
    }
    if (counter > 0)
    {
        istrue = true;
        return istrue;
    }
    else if (counter == 0)
    {
        return istrue;
    }
}
bool haslowercase(string userpassword, int length)
{

    bool istrue = false;
    int counter = 0;
    for (int i = 0; i <= length; i++)
    {
        if ((userpassword[i] >= 97) && (userpassword[i] <= 122))
        {
            counter++;
        }
    }
    if (counter > 0)
    {
        istrue = true;
        return istrue;
    }
    else
    {
        return istrue;
    }
}
bool validRole(string role) // validation to check role to sinup
{
    if (role == "Admin" || role == "admin" || role == "Customer" || role == "customer")
    {
        return true;
    }
    else
    {
        cout << "Invalid input!" << endl
             << "Enter role(Admin/admin or Customer/customer)" << endl;
        return 0;
    }
}
void clearscreen() // to clearscreen
{
    cout << "press any key to continue:";
    getch();
    system("cls");
    header();
}