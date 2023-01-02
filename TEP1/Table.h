class Table {
public:
    Table();
    Table(std::string name, int tableLength);
    Table(Table &pcOther);

    void setName(std::string name);
    bool setNewSize(int tableLength);
    Table *pcClone();
    void modifyArray(Table *table, int newSize);
    void modifyArray(Table table, int newSize);

    //testing methods
    void setValue(int index, int value);
    void printArray();
    std::string getName();

    ~Table();

    //constants
    const int DEFAULT_ARRAY_LENGTH = 16;
    const std::string DEFAULT_NAME = "Little table";

private:
    std::string name;
    int *array;
    int length;

    int *copyArray(int *array, int length);
    int *copyArray(int *array, int originalLength, int newLength);
    bool validSize(int size);

    const std::string DEFAULT_ERROR_MESSAGE = "Wrong size";

};








