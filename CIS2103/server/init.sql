-- Create the Users table
CREATE TABLE "Users" (
    "Id" SERIAL PRIMARY KEY,
    "UserName" VARCHAR(255) NOT NULL,
    "Password" VARCHAR(255) NOT NULL,
    "Role" INTEGER NOT NULL
);

-- Create the Blogs table
CREATE TABLE "Blogs" (
    "Id" SERIAL PRIMARY KEY,
    "Title" VARCHAR(255) NOT NULL,
    "Content" TEXT NOT NULL,
    "Likes" INTEGER NOT NULL,
    "AuthorId" INTEGER NOT NULL,
    "DatePosted" TIMESTAMP NOT NULL,
    CONSTRAINT "FK_Blogs_Users_AuthorId" FOREIGN KEY ("AuthorId") REFERENCES "Users" ("Id")
);

-- User Seeders
INSERT INTO "Users" ("UserName", "Password", "Role")
VALUES ('guest', 'guest12345', 0);
INSERT INTO "Users" ("UserName", "Password", "Role")
VALUES ('writer', 'writer12345', 1);
INSERT INTO "Users" ("UserName", "Password", "Role")
VALUES ('admin', 'admin12345', 2);