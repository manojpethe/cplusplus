#include <iostream>
#include <pqxx/pqxx> 
#include "./random.h"

int main() {
    connectionString = "dbname=postgres user=postgres password=postgres host=localhost port=5432";
    try {
        // connectionString = "dbname=postgres user=postgres password=postgres host=localhost port=5432";
        // Replace with your actual credentials
        pqxx::connection c(connectionString);
        // pqxx::connection c("dbname=postgres user=postgres password=postgres host=localhost port=5432");
        

        if (c.is_open()) {
            std::cout << "Connected to: " << c.dbname() << std::endl;
        } else {
            std::cerr << "Failed to open database" << std::endl;
            return 1;
        }

        // Transactions are used for executing queries
        pqxx::work tx{c};
        
        // Example: Execute a simple query
        pqxx::result r = tx.exec("SELECT 'Hello PostgreSQL!'");
        std::cout << r[0][0].as<std::string>() << std::endl;

        tx.commit(); // Finalize changes if any
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}