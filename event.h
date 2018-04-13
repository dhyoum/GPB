#include <string.h>

struct Event
{
    Event()
    {
		memset((unsigned char*)&data, 0xFF, sizeof(dataStructure));
    }
#pragma pack(1)
  struct dataStructure
  {
    int cid;
    int eid;
    int fid;
  } data;
#pragma pack()

	bool isAvailablecid()
	{
	  return (data.cid & 0x80) == 0;
	}

	bool isAvailableeid()
	{
	  return (data.eid & 0x80) == 0;
	}

    bool isValidcid()
    {
        if (data.cid==0x0ff)
            return false;

        return true;
    }
	
	
	void eidUnavailable()
	{
	  data.eid = 0x80;
	}
};

