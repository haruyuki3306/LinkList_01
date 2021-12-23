#include "ParserFrame.h"
#include <stdlib.h>

DataParser *createDataParser(FrameType type, int size, void *head, void *tail)
{
	DataParser *parser;
	parser = (DataParser *)malloc(sizeof(DataParser));
	if (parser==NULL)
	{
		return NULL;
	}
	parser->fType = type
}