class Table {
public:
    Table();
    Table(std::string name, int tableLength);
    Table(Table &pcOther);
    Table(Table &&other) noexcept;

    void setName(std::string name);
    bool setNewSize(int tableLength);
    Table *pcClone();
    void modifyArray(Table *table, int newSize);
    void modifyArray(Table table, int newSize);

    //testing methods
    void setValue(int index, int value);
    void printArray();
    std::string getName();
    int getLength() const;

    Table& operator=(const Table &pcOther);
    Table operator=(Table &&other);
    Table operator+(const Table &pcOther) const;
    int& operator[](int index);

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
    void move(Table &&other);

    friend std::ostream & operator<<(std::ostream& stream, const Table& table);

    const std::string DEFAULT_ERROR_MESSAGE = "Wrong size";

};








