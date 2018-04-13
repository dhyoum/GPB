#include <iostream>
#include <stdio.h>
#include <string>
#include <fstream>
#include "new_event.pb.h"

#include <google/protobuf/io/zero_copy_stream_impl_lite.h>

namespace gp = google::protobuf;

using namespace std;

int main()
{
    Event event1;

	fstream input("myfile", ios::in | ios::binary);
	event1.ParseFromIstream(&input);

    printf("Is valid : %s\n", event1.IsInitialized()?"ok":"nok");

    event1.DiscardUnknownFields();

    cout << event1.ShortDebugString() << endl;

    return 0;
}
