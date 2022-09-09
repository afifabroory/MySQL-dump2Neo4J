# MySQL Dump To Neo4J
> The project goals is high performance and improve efficiency for big MySQL dump import to Neo4J database
> 
> This project also focuses on comprehensive documentation

The project only recognize two statement, such as create table and insert value into table.

<!-- Program flow: \
[0] Program read files (SourceBuffer.cc/h) -> [1] Perform lexecial analysis (Lexer.cc/h) -> [2] Perform parsing (Parsing.cc/h) 
-> [3] If valid, then insert to Neo4J -->

## Background
Why? Well, I read Neo4J documentation that's to import MySQL dump into Neo4J database, the only possible way is to convert it first to CSV format and then from CSV import to Neo4J (Or maybe I search using wrong keyword??). This are not good in my case, where I have big MySQL dump and limited amount of spaces.

## References:
- https://github.com/yashsmehta/mysqldump-to-csv
- https://github.com/afifabroory/Propositional-Logic-Calculator
- https://gist.github.com/arrieta/1a309138689e09375b90b3b1aa768e20 (Simple C++ Lexer)
- https://github.com/pramttl/mlistdata-mysql-neo4j


# Note!
This project is currently designed for my purposes. Later I will make it more general purposes.