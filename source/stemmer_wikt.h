/*
	STEMMER_WIKT.H
	----------------
*/
#ifndef STEMMER_WIKT_H_
#define STEMMER_WIKT_H_

#include "stemmer.h"
#include "stem_wikt.h"

/*
	class ANT_STEMMER_WIKT
	------------------------
*/
class ANT_stemmer_wikt : public ANT_stemmer, public ANT_stem_wikt
{
public:
	ANT_stemmer_wikt(ANT_search_engine *search_engine) : ANT_stemmer(search_engine), ANT_stem_wikt() {}
	virtual size_t stem(const char *term, char *destination) { return ANT_stem_wikt::stem(term, destination); }
	
} ;

#endif  /* STEMMER_WIKT_H_ */