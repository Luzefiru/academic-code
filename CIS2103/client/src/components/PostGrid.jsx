import { useState, useEffect } from 'react';
import { Post } from './index.js';
import { PostService } from '../services';

function PostGrid() {
  const [posts, setPosts] = useState([]);
  const [isError, setIsError] = useState(false);
  const [isLoading, setIsLoading] = useState(true);

  useEffect(() => {
    const fetchPostsFromBackend = async () => {
      try {
        const fetchedPosts = await PostService.getPosts();
        console.log('Fetched Posts:');
        console.table(fetchedPosts);
        setPosts(fetchedPosts);
        setIsLoading(false);
      } catch (e) {
        console.error(e);
        setIsError(true);
        setIsLoading(false);
      }
    };
    fetchPostsFromBackend();
  }, []);

  if (isError) {
    return (
      <div className="grid gap-8 px-4 mb-20 PostGrid place-items-center md-grid-cols-2 lg:grid-cols-3 md:px-8">
        <article className="col-span-3 prose text-center">
          <h1 className="text-error">Something went wrong!</h1>
          <p>
            It seems your backend has issues. Check the logs for more
            information.
          </p>
        </article>
      </div>
    );
  }

  if (isLoading) {
    return (
      <div className="flex justify-center w-full">
        <span className="loading loading-spinner loading-lg"></span>
      </div>
    );
  }

  if (posts.length === 0) {
    return (
      <div className="grid gap-8 px-4 mb-20 PostGrid place-items-center md-grid-cols-2 lg:grid-cols-3 md:px-8">
        <article className="col-span-3 prose text-center">
          <h1 className="text-primary">No posts yet.</h1>
          <p>Create a new post by clicking the Create Post button!</p>
        </article>
      </div>
    );
  }

  return (
    <div className="grid gap-8 px-4 mb-20 PostGrid place-items-center md-grid-cols-2 lg:grid-cols-3 md:px-8">
      {posts.map((p) => (
        <Post key={p.id} id={p.id} title={p.title} content={p.content} />
      ))}
    </div>
  );
}

export default PostGrid;
