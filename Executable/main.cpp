#include <iostream>
#include <fstream>
#include <string>
#include "ProtoFiles/addressbook.pb.h"

void promptForAddress(tutorial::Person* person) {
 /* std::cout << "Enter person ID number: ";
  int id;
  std::cin >> id;
  person->set_id(id);
  std::cin.ignore(256, '\n');

  std::cout << "Enter name: ";
  std::getline(std::cin, *person->mutable_name());

  std::cout << "Enter email address (blank for none): ";
  std::string email;
  getline(std::cin, email);
  if(!email.empty()){
    person->set_email(email);
  }

  while(true) {
    std::cout << "Enter a phone number: ";
    std::string number;
    std::getline(std::cin, number);
    if (number.empty()) {
      break;
    }
    tutorial::Person::PhoneNumber* phone_number = person->add_phones();
    phone_number->set_number(number);


    std::cout << "Is this a mobile, home, or work phone? ";
    std::string type;
    std::getline(std::cin, type);
    if(type == "mobile")
    {
      phone_number->set_type(tutorial::Person::MOBILE);
    } else if (type == "home") {
      phone_number->set_type(tutorial::Person::HOME);
    } else if (type == "work") {
      phone_number->set_type(tutorial::Person::WORK);
    } else {
      std::cout << "Unknown phone type. Using default." << std::endl;
    }
  }*/
}

#include <iostream>

int main(int argc, char * argv[])
{
 // iboost::asio::io_service io_service;
 // for(int x = 0; x < 42; ++x)
 // {
 //   io_service.poll();
 //   std::cout << "Counter " << x << std::endl;
 // }

  

  if(argc != 2)
  {
    std::cout << "Usage: " << argv[0] << " ADDRESS_BOOK_FILE" << std::endl;
    return -1;
  }

  //tutorial::AddressBook address_book;
  //{
  //  std::fstream input(argv[1], std::ios::in | std::ios::binary);
  //  if(!input) 
  //  {
  //    std::cout << argv[1] << ": File not found. Creating a new file." <<
  //      std::endl;
  //  }
  //  //else if (!address_book.ParseFromIstream(&input)) 
  //  //{
  //  //  std::cout << "Failed to parse address book." << std::endl;
  //  //  return -1;
  //  //}
  //}
  ////std::cout << address_book.DebugString() << std::endl;

  //promptForAddress(address_book.add_people());

  //std::fstream output(argv[1], std::ios::out | std::ios::trunc | std::ios::binary);
  ////if(!address_book.SerializeToOstream(&output))
  ////{
  ////  std::cerr << "Failed to write address book. " << std::endl;
  ////  return -1;
  ////}
  ////google::protobuf::ShutdownProtobufLibrary();

  return 0;
}
