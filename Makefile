XX  = g++

CXXFLAGS =
CXXFLAGS += -O2 -g -std=c++11 -Wall

LDFLAGS = -lpthread -L/usr/local/lib `pkg-config --cflags --libs protobuf`
PROTOC = protoc

PROTOS_PATH = ./proto

vpath %.proto $(PROTOS_PATH)

all: example old new descriptor mesgoption fieldoption

example : producer.pb.o event_header.pb.o event.pb.o dis.o example.o
	$(CXX) $^ $(LDFLAGS) -o $@

example2 : example2.o dis.o
	$(CXX) $^ $(LDFLAGS) -o $@

old : old_event.pb.o old.o dis.o
	$(CXX) $^ $(LDFLAGS) -o $@

new : new_event.pb.o new.o dis.o
	$(CXX) $^ $(LDFLAGS) -o $@

descriptor : producer.pb.o event_header.pb.o event2.pb.o dis.o descriptor.o
	$(CXX) $^ $(LDFLAGS) -o $@

mesgoption : producer.pb.o event_header.pb.o event2.pb.o dis.o mesgoption.o
	$(CXX) $^ $(LDFLAGS) -o $@

fieldoption : producer.pb.o event_header.pb.o event2.pb.o dis.o fieldoption.o
	$(CXX) $^ $(LDFLAGS) -o $@

.PRECIOUS: %.pb.cc
%.pb.cc: %.proto
	$(PROTOC) -I $(PROTOS_PATH) --cpp_out=./ $<

clean:
	-rm -rf *.o *.pb.* example example2 example3 descriptor fieldoption newfile old new mesgoption
