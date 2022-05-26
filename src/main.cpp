#include <iostream>
#include <memory>

#include <sqlite3.h>

using namespace std;

int main(int argc, char **argv)
{
    cout << argv[0] << "\t"
         << "argc: " << argc << endl;

    try
    {
        sqlite3 *DB;
        bool conn = sqlite3_open("db_sqlite.db", &DB);

        if (conn)
        {
            throw sqlite3_errmsg(DB);
        }
        else
        {
            cout << "Conectado com sucesso!!!" << endl;
        }

        sqlite3_close(DB);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        return 1;
    }

    return 0;
}
