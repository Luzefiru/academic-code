-- Create the Todos table
CREATE TABLE "Todos" (
    "Id" SERIAL PRIMARY KEY,
    "Name" VARCHAR(255) NOT NULL,
    "IsComplete" BOOLEAN NOT NULL
);