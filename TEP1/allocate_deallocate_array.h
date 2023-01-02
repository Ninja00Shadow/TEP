void allocateArrayFill34(int size);

bool allocateArrayTwoDim(int ***twoDimArray, int sizeX, int sizeY);

bool deallocateArrayTwoDim(int ***twoDimArray, int sizeX, int sizeY);

bool deallocateArrayTwoDimLessParameters(int ***twoDimArray, int sizeX);

bool validSize(int size);

bool validSize(int sizeX, int sizeY);

void printTwoDimArray(int**& twoDimArray, int verses, int columns);

void fillAndPrintTwoDimArray(int**& twoDimArray, int verses, int columns);


const int DEFAULT_ARRAY_FILLING_NUMBER = 34;
const std::string DEFAULT_ERROR_MESSAGE = "Wrong size";

