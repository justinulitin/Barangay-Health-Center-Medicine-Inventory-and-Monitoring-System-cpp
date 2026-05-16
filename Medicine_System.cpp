#include <iostream>
#include <unordered_map>
#include <iomanip>
#include <ctime>
using namespace std;

struct Medicine {
    string name;
    string category;
    double stock;
    double max_stock;
    string unit;
    string expiry;
};

unordered_map<string, Medicine> medicines;

void displayMenu();
void addMedicine();
void viewMedicines();
void updateStock();
void checkLowStock();
void generateReport();

int main() {
    int choice;

    do {
        displayMenu();

        cout << "Enter your choice: ";

        if(!(cin >> choice)) {
            cin.clear();
            cin.ignore(1000, '\n');

            cout << "Invalid input. Numbers only.\n";
            continue;
        }

        cin.ignore();

        switch(choice) {
            case 1:
                addMedicine();
                break;

            case 2:
                viewMedicines();
                break;

            case 3:
                updateStock();
                break;

            case 4:
                checkLowStock();
                break;

            case 5:
                generateReport();
                break;

            case 6:
                cout << "Exiting system...\n";
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
        }

    } while(choice != 6);

    return 0;
}

void displayMenu() {
    cout << "\n======== BARANGAY HEALTH CENTER MEDICINE INVENTORY ========\n";
    cout << "1. Add Medicine\n";
    cout << "2. View Medicines\n";
    cout << "3. Update Stock\n";
    cout << "4. Check Low Stock Medicines\n";
    cout << "5. Generate Inventory Report\n";
    cout << "6. Exit\n";
    cout << "===========================================================\n";
}

void addMedicine() {
    string med_id;
    Medicine med;

    cout << "\n-------- ADD MEDICINE --------\n";

    cout << "Medicine ID: ";
    getline(cin, med_id);

    if(med_id.empty()) {
        cout << "Medicine ID cannot be empty.\n";
        return;
    }

    if(medicines.find(med_id) != medicines.end()) {
        cout << "Medicine ID already exists.\n";
        return;
    }

    cout << "Name: ";
    getline(cin, med.name);

    cout << "Category: ";
    getline(cin, med.category);

    cout << "Stock: ";

    while(!(cin >> med.stock) || med.stock < 0) {
        cin.clear();
        cin.ignore(1000, '\n');

        cout << "Invalid stock input. Enter valid number: ";
    }

    cout << "Maximum Capacity: ";

    while(!(cin >> med.max_stock) || med.max_stock <= 0) {
        cin.clear();
        cin.ignore(1000, '\n');

        cout << "Invalid maximum capacity. Enter valid number: ";
    }

    cin.ignore();

    if(med.stock > med.max_stock) {
        cout << "Stock cannot exceed maximum capacity.\n";
        return;
    }

    cout << "Unit (tablets, mL, mg, etc.): ";
    getline(cin, med.unit);

    cout << "Expiry: ";
    getline(cin, med.expiry);

    medicines[med_id] = med;

    cout << "Medicine added successfully!\n";
}

void viewMedicines() {
    if(medicines.empty()) {
        cout << "No medicines available.\n";
        return;
    }

    cout << "\n---------------------- ALL MEDICINES STORED ----------------------\n";

    cout << left
         << setw(10) << "ID"
         << setw(20) << "Name"
         << setw(20) << "Category"
         << setw(20) << "Stock"
         << setw(20) << "Max Capacity"
         << setw(15) << "Expiry" << endl;

    for(auto x : medicines) {

        string stock_display =
            to_string(x.second.stock) + " " + x.second.unit;

        string max_display =
            to_string(x.second.max_stock) + " " + x.second.unit;

        cout << left
             << setw(10) << x.first
             << setw(20) << x.second.name
             << setw(20) << x.second.category
             << setw(20) << stock_display
             << setw(20) << max_display
             << setw(15) << x.second.expiry
             << endl;
    }
}

void updateStock() {
    string med_id;
    double quantity;

    cout << "\n-------- UPDATE STOCK --------\n";

    cout << "Enter Medicine ID: ";
    getline(cin, med_id);

    if(medicines.find(med_id) == medicines.end()) {
        cout << "Medicine not found.\n";
        return;
    }

    cout << "\nMedicine Found:\n";

    cout << medicines[med_id].name << " | "
         << medicines[med_id].category << " | "
         << medicines[med_id].stock << " "
         << medicines[med_id].unit << " | Max: "
         << medicines[med_id].max_stock << " "
         << medicines[med_id].unit << endl;

    cout << "\nEnter Quantity to Add: ";

    while(!(cin >> quantity) || quantity < 0) {
        cin.clear();
        cin.ignore(1000, '\n');

        cout << "Invalid quantity. Enter valid number: ";
    }

    cin.ignore();

    if(medicines[med_id].stock + quantity >
       medicines[med_id].max_stock) {

        cout << "Warning: Stock cannot exceed maximum capacity.\n";
    }
    else {
        medicines[med_id].stock += quantity;

        cout << "Stock updated successfully.\n";
    }
}

void checkLowStock() {

    if(medicines.empty()) {
        cout << "No medicines available.\n";
        return;
    }

    bool found = false;

    cout << "\n-------- LOW STOCK MEDICINES --------\n";

    for(auto x : medicines) {

        double percentage =
            (x.second.stock / x.second.max_stock) * 100;

        string status;

        if(percentage <= 30)
            status = "Critical Low Stock";

        else if(percentage < 50)
            status = "Low Stock";

        else
            continue;

        found = true;

        cout << x.first << " | "
             << x.second.name << " | "
             << x.second.stock << " "
             << x.second.unit << " | "
             << status << endl;
    }

    if(!found) {
        cout << "All medicines are sufficiently stocked.\n";
    }
}

void generateReport() {

    time_t now = time(0);
    char* dt = ctime(&now);

    cout << "\nBARANGAY HEALTH CENTER MEDICINE INVENTORY REPORT\n";
    cout << "Generated on: " << dt << endl;

    cout << "-------------------------------------------------------------\n";

    if(medicines.empty()) {
        cout << "No medicines available.\n";
        return;
    }

    int total_med = medicines.size();

    for(auto x : medicines) {

        double percentage =
            (x.second.stock / x.second.max_stock) * 100;

        string status;

        if(percentage <= 30)
            status = "Critical Low Stock";

        else if(percentage < 50)
            status = "Low Stock";

        else
            status = "In Stock";

        cout << "Medicine ID: " << x.first << endl;
        cout << "Name: " << x.second.name << endl;
        cout << "Category: " << x.second.category << endl;
        cout << "Expiry: " << x.second.expiry << endl;

        cout << "Current Stock: "
             << x.second.stock << " "
             << x.second.unit << endl;

        cout << "Maximum Capacity: "
             << x.second.max_stock << " "
             << x.second.unit << endl;

        cout << "Stock Percentage: "
             << percentage << "%" << endl;

        cout << "Status: " << status << endl;

        cout << "-------------------------------------------------------------\n";
    }

    cout << "Total Medicines: " << total_med << endl;

    cout << "Inventory report generated successfully.\n";
}