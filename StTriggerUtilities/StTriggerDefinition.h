// -*- mode:c++ -*-

#ifndef StTriggerDefinition_h
#define StTriggerDefinition_h

#include <cstdio>
#include "TObject.h"
#include "TString.h"

struct StTriggerDefinition : public TObject {
  int triggerIndex;		// trigger index
  TString name;			// trigger name
  int triggerId;		// trigger ID
  unsigned int onbits;	        // bits required to be ON at input of TCU
  unsigned int offbits;	        // bits required to be OFF at input of TCU
  unsigned int onbits0;
  unsigned int onbits1;
  unsigned int onbits2;
  unsigned int onbits3;
  unsigned int offbits0;
  unsigned int offbits1;
  unsigned int offbits2;
  unsigned int offbits3;

  void print();

  ClassDef(StTriggerDefinition,1)
};

inline void StTriggerDefinition::print()
{
  printf("triggerIndex=%d name=%s triggerId=%d onbits=0x%04x offbits=0x%04x\n",
	 triggerIndex,name.Data(),triggerId,onbits,offbits);
}

#endif	// StTriggerDefinition_h
