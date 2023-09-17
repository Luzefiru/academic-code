import { Todo } from '../hooks/useTodo';

interface Props {
  todo: Todo;
  deleteTodo: (id: number) => void;
  updateTodo: (id: number, title: string, content: string) => void;
}

export default function TodoItem({ todo }: Props) {
  return (
    <div className="flex gap-2">
      <div className="font-bold">{todo.title}</div>
      <div className="font-italic">{todo.content}</div>
    </div>
  );
}
