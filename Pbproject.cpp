// Pbproject.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include "Final.pb.h"
using namespace std;



int _tmain(int argc, _TCHAR* argv[])
{
	GOOGLE_PROTOBUF_VERIFY_VERSION;

	tutorial::Person person;
	
		// Read the existing part book.
		fstream input("Person.pb", ios::in | ios::binary);
		if (!input) {
			cout << argv[1] << ": File not found.  Creating a new file." << endl;
		}
		else if (!person.ParseFromIstream(&input)) {
			cerr << "Failed to parse part book." << endl;
			return -1;
		}

		cout << "Id" << " " << "Name" << "    " << "Email" << endl;
		cout << person.id() << " " << person.name() << " " << person.email();
	
		person.set_name("Vinay");
		person.set_id(person.id() + 1);
		person.set_email("vinjain1012@gmail.com");
	

	{
		// Write the new part book back to disk.
			fstream output("Person.pb", ios::out | ios::trunc | ios::binary);
		if (!person.SerializeToOstream(&output)) {
			cerr << "Failed to write part book." << endl;
			return -1;
		}
	}

	// Optional:  Delete all global objects allocated by libprotobuf.
	google::protobuf::ShutdownProtobufLibrary();

	return 0;	
}

