class Printer {
public:
    virtual void print() = 0;
};

class Scanner {
public:
    virtual void scan() = 0;
};

class BasicPrinter : public Printer {
public:
    void print() override {
        // 문서 출력
    }
};

class MultiFunctionDevice {//
private:
    Printer* printer;
    Scanner* scanner;

public:
    MultiFunctionDevice(Printer* p, Scanner* s) : printer(p), scanner(s) {}

    void print() {
        if (printer) printer->print();
    }

    void scan() {
        if (scanner) scanner->scan();
    }
};
