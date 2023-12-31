#pragma once
#include <iostream>
#include <iomanip>
#include "clsUser.h"
#include "Global.h"
#include "clsAddDate.h"
using namespace std;

class clsScreen
{
protected:

    static void _DrawScreenHeader(string Title, string SubTitle = "")
    {
        cout << right << setw(82) << "___________________________________________\n";
        cout << "\n\t\t\t\t\t  " << Title << endl;
        if (SubTitle != "")
        {
            cout << "\n\t\t\t\t\t  " << SubTitle << endl;
        }
        cout <<  right << setw(82) << "___________________________________________\n\n";

        cout << right << setw(45) << "User : " << clsAddDate::LoggedCurrentUser() << endl;
        cout << right << setw(48) << clsAddDate::GetDate() << "\n\n ";
    }

    static bool CheckAccessRights(clsUser::enPermissions Permission)
    {

        if (!CurrentUser.CheckAccessPermission(Permission))
        {
            cout << "\t\t\t\t\t______________________________________";
            cout << "\n\n\t\t\t\t\t  Access Denied! Contact your Admin.";
            cout << "\n\t\t\t\t\t______________________________________\n\n";
            return false;
        }
        else
        {
            return true;
        }

    }
};

