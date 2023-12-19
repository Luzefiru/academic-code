# MessageBoard

An inclusive message board platform with role-based access control, enabling users to effortlessly share, discover, and manage content according to roles as guests, writers, or administrators.

## Usage

For the frontend, simply run the following commands:

```bash
cd client
npm install && npm run dev
```

For the backend, you'll need the C# 8.0 SDK and Docker with `docker compose`.

```bash
cd server
dotnet restore
docker compose up && dotnet watch
```

## Features

1. **User Authentication:**
   - Barebones authentication with `localStorage` persistence.
2. **Role-Based Access Control:**
   - Three distinct user roles: Guest, Writer, and Admin, with varying permissions.
3. **Post Management:**
   - View all blog posts or access a specific post by its unique ID.
   - Create new blog posts.
   - Delete owned posts (Writers) or any post (Admins).
4. **Interactivity:**
   - Like posts to express appreciation or support.

## Endpoints

#### User & Authentication

- **POST /auth/login**

  - Description: Endpoint to authenticate users via their UserName and Password.
  - If successful, it returns the user's `{Id, UserName, Password, Role}` fields.

- **GET /user/{id}**
  - Description: Retrieves a user by their `Id`.

#### Blog Posts

- **GET /blogs**
  - Description: Retrieve all blog posts.
- **GET /blogs/{id}**
  - Description: Retrieve a specific blog post by ID.
- **POST /blogs**
  - Description: Create a new blog post.
  - Authorization: `writer` or `admin` role required by checking if the request body's `Role` is either `1` or `2`, respectively.
- **DELETE /blogs/{id}**
  - Description: Delete a specific blog post by ID.
  - Authorization: `writer` (only for their own posts) or `admin` role required by checking if the request body's `Role` is either `1` or `2`, respectively.

#### User Actions

- **POST /blogs/{id}/like**
  - Description: Like a specific blog post.
  - Authorization: `user`, `writer`, or `admin` role required, request body's `Role` field must be a number from `0` to `2` inclusive.

### User Roles

- **Guest Role**:
  - value is `0`
  - Can view blog posts.
  - Can like blog posts.
- **Writer Role** (Includes Guest permissions +):
  - value is `1`
  - Can create new blog posts.
  - Can delete their own blog posts.
- **Admin Role** (Includes Writer permissions +):
  - value is `2`
  - Can delete any blog post.
