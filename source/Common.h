#ifndef COMMON_H_
#define COMMON_H_

#include <string>
#include <unistd.h>
#include <vector>

typedef std::vector<std::string> StringVec;
typedef std::vector<int> IntVec;
typedef std::vector<char*> BufferVec;
typedef std::vector<size_t> SizeTVec;
typedef std::vector<uint64_t> UInt64Vec;


#define STRINGIZE(value)		_STRINGIZE(value) // 2 levels necessary for macro expansion
#define _STRINGIZE(value)		#value

#define PHASENAME_IDLE			"IDLE"
#define PHASENAME_TERMINATE		"QUIT"
#define PHASENAME_CREATEDIRS	"MKDIRS"
#define PHASENAME_CREATEFILES	"WRITE"
#define PHASENAME_READFILES		"READ"
#define PHASENAME_DELETEFILES	"RMFILES"
#define PHASENAME_DELETEDIRS	"RMDIRS"
#define PHASENAME_SYNC			"SYNC"
#define PHASENAME_DROPCACHES	"DROPCACHE"
#define PHASENAME_STATFILES		"STAT"


#define PHASEENTRYTYPE_DIRS		"dirs"
#define PHASEENTRYTYPE_FILES	"files"

#define HTTP_PROTOCOLVERSION	"1.7.0" // exchanged between client & server to check compatibility


#define SAFE_DELETE(objectPointer) \
	do \
	{ \
		if(objectPointer) \
		{ \
			delete(objectPointer); \
			objectPointer = NULL; \
		}  \
	} while(0)

#define SAFE_FREE(pointer) \
	do \
	{ \
		if(pointer) \
		{ \
			free(pointer); \
			pointer = NULL; \
		}  \
	} while(0)


enum BenchPhase
{
	BenchPhase_IDLE = 0,
	BenchPhase_TERMINATE, // tells workers to self-terminate when all is done
	BenchPhase_CREATEDIRS,
	BenchPhase_DELETEDIRS,
	BenchPhase_CREATEFILES,
	BenchPhase_DELETEFILES,
	BenchPhase_READFILES,
	BenchPhase_SYNC,
	BenchPhase_DROPCACHES,
	BenchPhase_STATFILES,
};

enum BenchPathType
{
	BenchPathType_DIR=0,
	BenchPathType_FILE=1,
	BenchPathType_BLOCKDEV=2,
};


#endif /* COMMON_H_ */
