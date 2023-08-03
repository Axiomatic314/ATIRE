/*
	STEM_WIKT.H
	--------
*/
#ifndef STEM_WIKT_H_
#define STEM_WIKT_H_

#include <unordered_map>
#include <string>
#include "stem.h"

/*
	class ANT_STEM_WIKT
	----------------
*/
class ANT_stem_wikt : public ANT_stem
{
private:
    std::unordered_map<std::string,std::string> lookup_table;
public:
	ANT_stem_wikt() ;
	virtual ~ANT_stem_wikt() {}
	virtual size_t stem(const char *term, char *destination);
	virtual char *name(void) { return "Wikt Stemmer"; }
} ;

#endif /* STEM_WIKT_H_ */