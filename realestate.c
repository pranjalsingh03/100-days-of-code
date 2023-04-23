// // #include <stdio.h>
// // #include <stdlib.h>
// // #include <string.h>

// // void add_record();
// // void display_Property();
// // void search_record();
// // void buySell();
// // void edit_record();
// // void delete_record();

// // // structure for storing property details
// // struct property
// // {
// //     char property_type[20];
// //     char property_location[50];
// //     int bhk;
// //     int area;
// //     float price;
// // };

// // // main function
// // int main() {
// //     int choice, count=0;
// //     struct property prop[100];
// //     while(1) {
// //         printf("\nEnter your choice:\n");
// //         printf("1. Add New Property Record\n");
// //         printf("2. Display Available Properties\n");
// //         printf("3. Search Properties\n");
// //         // printf("4
// //          printf("5. Buy/Sell Property\n");
// //         printf("6. Edit Property Record\n");
// //         printf("7. Delete Property Record\n");
// //         printf("8. Exit\n");
// //         printf("Choice: ");
// //         scanf("%d", &choice);
// //         switch(choice) {
// //             case 1:
// //                 add_record(prop, &count);
// //                 break;
// //             case 2:
// //                 display_Property(prop, count);
// //                 break;
// //             case 3:
// //                 search_record(prop, count);
// //                 break;
// //             case 4:
// //                 buySell(prop, &count);
// //                 break;
// //             // case 5:
// //             //     buy_sell_record(prop, &count);
// //             //     break;
// //             case 6:
// //                 edit_record(prop, count);
// //                 break;
// //             case 7:
// //                 delete_record(prop, &count);
// //                 break;
// //             case 8:
// //                 exit(0);
// //             default:
// //                 printf("\nInvalid choice.\n");
// //                 break;
// //         }
// //     }
// //     return 0;
// // }
// // // function to add new property record

// // // Function to add a new record
// // void add_record(struct property prop[], int *count) {
// //     printf("\nEnter property details:\n");
// //     printf("Property Type: ");
// //     scanf("%s", prop[*count].property_type);
// //     printf("Property Location: ");
// //     scanf("%s", prop[*count].property_location);
// //     printf("BHK: ");
// //     scanf("%d", &prop[*count].bhk);
// //     printf("Area (in sq. ft.): ");
// //     scanf("%d", &prop[*count].area);
// //     printf("Price (in lakhs): ");
// //     scanf("%f", &prop[*count].price);
// //     (*count)++;
// //     printf("\nRecord added successfully.\n");
// // }

// // // function to display all available properties
// // void display_Property(struct property *prop, int count) {
// //     if(count == 0) {
// //         printf("\nNo properties available.\n");
// //         return;
// //     }
// //     printf("\nAvailable Properties:\n");
// //     printf("----------------------------------------------------------------------\n");
// //     printf("Property Type\tLocation\t\tBHK\tArea (sq.ft)\tPrice (in lakhs)\n");
// //     printf("----------------------------------------------------------------------\n");
// //     for(int i=0; i<count; i++) {
// //         printf("%s\t\t%s\t\t%d\t%d\t\t%.2f\n", prop[i].property_type, prop[i].property_location, prop[i].bhk, prop[i].area, prop[i].price);
// //     }
// // }

// // void buySell(struct property prop[], int *count) {
// //     int choice, id;
// //     printf("\nEnter 1 to buy a property or 2 to sell a property: ");
// //     scanf("%d", &choice);

// //     switch (choice) {
// //         case 1:
// //             printf("\nAvailable Properties:\n");
// //             display_Property(prop, count);

// //             printf("\nEnter Property ID to buy: ");
// //             scanf("%d", &id);
// //             if (id <= 0 || id > *count) {
// //                 printf("\nInvalid Property ID.\n");
// //                 return;
// //             }

// //             printf("\nYou have selected the following property:\n");
// //             printf("------------------------------------------------------------\n");
// //             printf("| %-15s | %-20s | %-3s | %-7s | %-8s |\n", "Property Type", "Property Location", "BHK", "Area", "Price");
// //             printf("------------------------------------------------------------\n");
// //             printf("| %-15s | %-20s | %-3d | %-7d | %-8.2f |\n", prop[id-1].property_type, prop[id-1].property_location, prop[id-1].bhk, prop[id-1].area, prop[id-1].price);
// //             printf("------------------------------------------------------------\n");

// //             printf("\nEnter your details:\n");
// //             char name[50], contact[20];
// //             printf("Name: ");
// //             scanf("%s", name);
// //             printf("Contact Number: ");
// //             scanf("%s", contact);

// //             printf("\nCongratulations %s, you have successfully bought the property!\n", name);

// //             // Delete the property from the database
// //             for (int i = id-1; i < *count-1; i++) {
// //                 prop[i] = prop[i+1];
// //             }
// //             (*count)--;
// //             break;
// //         case 2:
// //             printf("\nEnter details of the property to sell:\n");
// //             printf("Property Type: ");
// //             scanf("%s", prop[*count].property_type);
// //             printf("Property Location: ");
// //             scanf("%s", prop[*count].property_location);
// //             printf("BHK: ");
// //             scanf("%d", &prop[*count].bhk);
// //             printf("Area (in sq. ft.): ");
// //             scanf("%d", &prop[*count].area);
// //             printf("Price: ");
// //             scanf("%f", &prop[*count].price);

// //             printf("\nYour property has been added to the database with the following details:\n");
// //             printf("------------------------------------------------------------\n");
// //             printf("| %-15s | %-20s | %-3s | %-7s | %-8s |\n", "Property Type", "Property Location", "BHK", "Area", "Price");
// //             printf("------------------------------------------------------------\n");
// //             printf("| %-15s | %-20s | %-3d | %-7d | %-8.2f |\n", prop[*count].property_type, prop[*count].property_location, prop[*count].bhk, prop[*count].area, prop[*count].price);
// //             printf("------------------------------------------------------------\n");
// //             (*count)++;
// //             break;
// //         default:
// //             printf("\nInvalid Choice!\n");
// //     }
// // }

// // // function to edit property details
// // void edit_record(struct property *prop, int count) {
// //     int index;
// //     printf("\nEnter index of property to edit: ");
// //     scanf("%d", &index);
// //     if(index >= 0 && index < count) {
// //         printf("\nEnter new property details:\n");
// //         printf("Property Type: ");
// //         scanf("%s", prop[index].property_type);
// //         printf("Property Location: ");
// //         scanf(" %[^\n]", prop[index].property_location);
// //         printf("BHK: ");
// //         scanf("%d", &prop[index].bhk);
// //         printf("Area (in sq.ft): ");
// //         scanf("%d", &prop[index].area);
// //         printf("Price (in lakhs): ");
// //         scanf("%f", &prop[index].price);
// //         printf("\nRecord updated successfully!\n");
// //     } else {
// //         printf("\nInvalid index.\n");
// //     }
// // }

// // // function to delete property record
// // void delete_record(struct property *prop, int *count) {
// //     int index;
// //     printf("\nEnter index of property to delete: ");
// //     scanf("%d", &index);
// //     if(index >= 0 && index < *count) {
// //         for(int i=index; i<*count-1; i++) {
// //             prop[i] = prop[i+1];
// //         }
// //         (*count)--;
// //         printf("\nRecord deleted successfully!\n");
// //     } else {
// //         printf("\nInvalid index.\n");
// //     }
// // }

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #define MAX_RECORDS 50
// struct property
// {
//     char address[50];
//     char type[50];
//     int price;
// };
// // Function to add a new property record
// void add_new_record(struct property *records, int *num_records)
// {
//     // Check if maximum number of records has been reached
//     if (*num_records == MAX_RECORDS)
//     {
//         printf("Maximum number of records reached.\n");
//         return;
//     }
//     // Get new record details from user
//     printf("Enter property address: ");
//     scanf(" %[^\n]", records[*num_records].address);
//     printf("Enter property type: ");
//     scanf(" %[^\n]", records[*num_records].type);
//     printf("Enter property price: ");
//     scanf("%d", &records[*num_records].price);
//     // Increase number of records
//     (*num_records)++;
//     printf("Record added.\n");
// }
// // Function to display available property
// void display_record(struct property *records, int num_records)
// {
//     // Check if there are any records
//     if (num_records == 0)
//     {
//         printf("No records available.\n");
//         return;
//     }
//     // Display all available properties
//     printf("%-20s %-20s %-10s\n", "Address", "Type", "Price");
//     for (int i = 0; i < num_records; i++)
//     {
//         if (records[i].price > 0)
//         {
//             printf("%-20s %-20s $%-9d\n", records[i].address,
//                    records[i].type, records[i].price);
//         }
//     }
// }
// // Function to search for a property record
// void search_record(struct property *records, int num_records)
// {
//     // Check if there are any records
//     if (num_records == 0)
//     {
//         printf("No records available.\n");
//         return;
//     }
//     // Get search query from user
//     char search_query[50];
//     printf("Enter property address or type to search: ");
//     scanf(" %[^\n]", search_query);
//     // Search for property record
//     int found = 0;
//     for (int i = 0; i < num_records; i++)
//     {
//         if (strcmp(records[i].address, search_query) == 0 ||
//             strcmp(records[i].type, search_query) == 0)
//         {
//             printf("%-20s %-20s $%-9d\n", records[i].address,
//                    records[i].type, records[i].price);
//             found = 1;
//         }
//     }
//     // Display message if no record was found
//     if (!found)
//     {
//         printf("No matching records found.\n");
//     }
// }
// // Function to buy/sell a property record
// void buy_sell_record(struct property *records, int num_records)
// {
//     // Check if there are any records
//     if (num_records == 0)
//     {
//         printf("No records available.\n");
//         return;
//     }
//     // Get address of property to buy/sell from user
//     char address[50];
//     printf("Enter property address to buy/sell: ");
//     scanf(" %[^\n]", address);
//     // Search for property record
//     int index = -1;
//     for (int i = 0; i < num_records; i++)
//     {
//         if (strcmp(records[i].address, address) == 0)
//         {
//             index = i;
//             break;
//         }
//     }
//     // Display message if property was not found
//     if (index == -1)
//     {
//         printf("Property");
//     } // Display property details
//     printf("%-20s %-20s $%-9d\n", records[index].address,
//            records[index].type, records[index].price);
//     // Get transaction type from user
//  printf("Enter buy to buy property or sell to sell property: "); 
//  char transaction_type[10]; 
//  scanf(" %[^\n]", transaction_type); 
//  // Perform transaction
//  if (strcmp(transaction_type, "buy") == 0) 
//  {
//         if (records[index].price == 0)
//         {
//             printf("This property is not for sale.\n");
//         }
//         else
//         {
//             printf("Property bought for $%d.\n",
//                    records[index].price);
//             records[index].price = 0;
//         } 
//  } 
//  else if (strcmp(transaction_type, "sell") == 0) 
//  {
//         if (records[index].price > 0)
//         {
//             printf("This property is already for sale.\n");
//         }
//         else
//         {
//             printf("Enter new property price: ");
//             scanf("%d", &records[index].price);
//             printf("Property put up for sale for $%d.\n",
//                    records[index].price);
//         } 
//  } 
//  else
//  {
//         printf("Invalid transaction type.\n"); 
//  }
// }
// // Function to edit/delete a property record
// // void edit_delete_record(struct property *records, int
// //                                                       *num_records)
// // {
// //  // Check if there are any records
// //  if (*num_records == 0)
// //  {
// //      printf("No records available.\n");
// //      return;
// //  } // Get address of property to edit/delete from user
// //  char address[50];
// //  printf("Enter property address to edit/delete: ");
// //  scanf(" %[^\n]", address);
// //  // Search for property record
// //  int index = -1;
// //  for (int i = 0; i < *num_records; i++)
// //  {
// //      if (strcmp(records[i].address, address) == 0)
// //      {
// //          index = i;
// //          break;
// //      }
// //  }
// //  // Display message if property was not found
// //  if (index == -1)
// //  {
// //      printf("Property not found.\n");
// //      return;
// //  }
// //  // Display property details
// //  printf("%-20s %-20s $%-9d\n", records[index].address,
// //         records[index].type, records[index].price);
// //  // Get action from user
// //  printf("Enter edit to edit property or delete to delete property: "); 
// //  char action[10]; 
// //  scanf(" %[^\n]", action); 
// //  // Perform action
// //  if (strcmp(action, "edit") == 0) 
// //  {
// //         // Get new property details from user
// //         printf("Enter new property address leave blank to keep 
// //                current value %s: ",records[index].address);
// //         char new_address[50];
// //         scanf(" %[^\n]", new_address);
// //         if (strcmp(new_address, "") != 0)
// //         {
// //             strcpy(records[index].address, new_address);
// //         }
// //         printf("Enter new property type leave blank to keep 
// //                current value %s: ",
// //                records[index].type);
// //         char new_type[50];
// //         scanf(" %[^\n]", new_type);
// //         if (strcmp(new_type, "") != 0)
// //         {
// //             strcpy(records[index].type, new_type);
// //         }
// //         printf("Enter new property price leave blank to keep 
// //                current value %d: ",
// //                records[index].price);
// //         char new_price_str[50];
// //         scanf(" %[^\n]", new_price_str);
// //         if (strcmp(new_price_str, "") != 0)
// //         {
// //             int new_price = atoi(new_price_str);
// //             records[index].price = new_price;
// //         }
// //         printf("Property details updated.\n"); 
// //  } 
// //  else if (strcmp(action, "delete") == 0) 
// //  {
// //         // Delete property record
// //         for (int i = index; i < *num_records - 1; i++)
// //         {
// //             records[i] = records[i + 1];
// //         }
// //         (*num_records)--;
// //         printf("Property record deleted.\n"); 
// //  } 
// //  else
// //  {
// //         printf("Invalid action.\n"); 
// //  }
// // }
// int main()
// {
//  struct property records[MAX_RECORDS];
//  int num_records = 0; // Display menu
//  while (1)
//  {
//      printf("\nReal Estate Management System\n");
//      printf("1. Add new property record\n");
//      printf("2. Display available properties\n");
//      printf("3. Search property\n");
//      printf("4. Buy/sell property\n");
//      printf("5. Edit/delete property record\n");
//      printf("6. Exit\n");
//      // Get user input
//      int choice;
//      printf("Enter your choice (1-6): ");
//      scanf("%d", &choice);
//      // Perform action based on user choice
//      switch (choice)
//      {
//      case 1:
//          add_new_record(records, &num_records);
//          break;
//      case 2:
//          display_record(records, num_records);
//          break;
//      case 3:
//          search_record(records, num_records);
//          break;
//      case 4:
//          buy_sell_record(records, num_records);
//          break;
//      case 5:
//         //  edit_delete_record(records, &num_records);
//          break;
//      case 6:
//          exit(0);
//      default:
//          printf("Invalid choice.\n");
//          break;
//      }
//  }
//  return 0;
// }


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PROPERTIES 100

void load_properties();
void save_properties();
void add_property();
void display_properties();
void search_properties();
void buy_property();
void sell_property();
void sell();

struct property
{
int id;
char type[20];
char location[20];
int area;
int bedrooms;
int budget;
char status[10];
};

struct property properties[MAX_PROPERTIES];
int num_properties = 0;

int main()
{
int choice;
load_properties();

do
{
printf("Real Estate Advisor\n");
printf("-------------------\n");
printf("1. Add new property\n");
printf("2. Display available properties\n");
printf("3. Search for properties\n");
printf("4. Buy a property\n");
printf("5. Sell a property\n");
printf("6. Exit\n");
printf("Enter your choice: ");
scanf("%d", &choice);
printf("\n");

switch (choice)
{
case 1:
add_property();
break;
case 2:
display_properties();
break;
case 3:
search_properties();
break;
case 4:
buy_property();
break;
case 5:
sell_property();
break;
case 6:
save_properties();
printf("Exiting program...\n");
break;
default:
printf("Invalid choice, try again.\n");
break;
}

printf("\n");
} while (choice != 6);

return 0;
}

void load_properties()
{
FILE *fp = fopen("properties.txt", "r");
if (fp == NULL)
{
return;
}
while (!feof(fp))
{
struct property p;
fscanf(fp, "%d %s %s %d %d %d %s\n", &p.id, p.type, p.location, &p.area, &p.bedrooms, &p.budget, p.status);
properties[num_properties++] = p;
}
fclose(fp);
}

void save_properties()
{
int i;
FILE *fp = fopen("properties.txt", "a");
for ( i = 0; i < num_properties; i++)
{
fprintf(fp, "%d %s %s %d %d %d %s\n", properties[i].id, properties[i].type, properties[i].location, properties[i].area, properties[i].bedrooms, properties[i].budget, properties[i].status);
}
fclose(fp);
}

void add_property()
{
struct property p;
printf("Enter property details:\n");
printf("ID: ");
scanf("%d", &p.id);
printf("Type: ");
scanf("%s", p.type);
printf("Location: ");
scanf("%s", p.location);
printf("Area: ");
scanf("%d", &p.area);
printf("Bedrooms: ");
scanf("%d", &p.bedrooms);
printf("Budget: ");
scanf("%d", &p.budget);
strcpy(p.status, "Available");

properties[num_properties++] = p;
save_properties();
printf("Property added successfully.\n");
}

void display_properties()
{
int i;
printf("ID Type Location Area Bedrooms Budget Status\n");
printf("---------------------------------------------------------------------\n");
for ( i = 0; i < num_properties; i++)
{
if (strcmp(properties[i].status, "Available") == 0)
{
printf("%-4d%-18s%-18s%-6d%-10d%-8d%s\n", properties[i].id, properties[i].type, properties[i].location, properties[i].area, properties[i].bedrooms, properties[i].budget, properties[i].status);
}
}
}

void search_properties()
{
int i ;
int min_area, min_bedrooms, max_budget;
printf("Enter search criteria:\n");
printf("Minimum area: ");
scanf("%d", &min_area);
printf("Minimum bedrooms: ");
scanf("%d", &min_bedrooms);
printf("Maximum budget: ");
scanf("%d", &max_budget);

printf("Search results:\n");
printf("ID Type Location Area Bedrooms Budget Status\n");
printf("---------------------------------------------------------------------\n");
for (i= 0; i < num_properties; i++)
{
if (strcmp(properties[i].status, "Available") == 0 &&
properties[i].area >= min_area &&
properties[i].bedrooms >= min_bedrooms &&
properties[i].budget <= max_budget)
{
printf("%-4d%-18s%-18s%-6d%-10d%-8d%s\n", properties[i].id, properties[i].type,
properties[i].location, properties[i].area, properties[i].bedrooms,
properties[i].budget, properties[i].status);
}
}
}

void buy_property()
{
int i;
int id;
printf("Enter property ID: ");
scanf("%d", &id);

for (i = 0; i < num_properties; i++)
{
if (properties[i].id == id && strcmp(properties[i].status, "Available") == 0)
{
strcpy(properties[i].status, "Sold");
save_properties();
printf("Property bought successfully.\n");
return;
}
}
printf("Property not found or not available.\n");
}

void edit_property()
{
int id,i;
printf("Enter property ID: ");
scanf("%d", &id);

for (i = 0; i < num_properties; i++)
{
if (properties[i].id == id)
{
printf("Enter new property details:\n");
printf("Type: ");
scanf("%s", properties[i].type);
printf("Location: ");
scanf("%s", properties[i].location);
printf("Area: ");
scanf("%d", &properties[i].area);
printf("Bedrooms: ");
scanf("%d", &properties[i].bedrooms);
printf("Budget: ");
scanf("%d", &properties[i].budget);
save_properties();
printf("Property edited successfully.\n");
return;
}
}
printf("Property not found.\n");
}

void sell_property() {
int id;
printf("Enter property ID: ");
scanf("%d", &id);
sell(id);
for (int i = 0; i < num_properties; i++) {
if (properties[i].id == id && strcmp(properties[i].status, "Sold") == 0) {
strcpy(properties[i].status, "Available");
save_properties();
printf("Property sold successfully.\n");
return;
}
}
printf("Property not found or not sold.\n");
}


void sell(int id) {
FILE *fp;
FILE *temp;
struct property p;
int found = 0;

fp = fopen("properties.txt", "r");
if (fp == NULL) {
printf("Error: Could not open file.\n");
exit(1);
}

temp = fopen("temp.txt", "w");
if (temp == NULL) {
printf("Error: Could not create temporary file.\n");
exit(1);
}

while (fread(&p, sizeof(struct property), 1, fp) == 1) {
if (p.id == id) {

strcpy(p.status, "Sold");
found = 1;
}

fwrite(&p, sizeof(struct property), 1, temp);
}

fclose(fp);
fclose(temp);

remove("properties.txt");

rename("temp.txt", "properties.txt");
}
void delete_property()
{
int id,i,j;
printf("Enter property ID: ");
scanf("%d", &id);

for (i = 0; i < num_properties; i++)
{
if (properties[i].id == id)
{
for (j = i; j < num_properties - 1; j++)
{
properties[j] = properties[j + 1];
}
num_properties--;
save_properties();
printf("Property deleted successfully.\n");
return;
}
}
printf("Property not found.\n");
}