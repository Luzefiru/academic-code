export default function Sales({ sales }) {
  return (
    <div className="stats outline outline-1 w-fit">
      <div className="stat">
        <div className="stat-title">Total Sales</div>
        <div className="stat-value text-success">
          ₱ {(Math.round(sales * 100) / 100).toFixed(2)}
        </div>
        <div className="pt-2 stat-desc">based on tickets</div>
      </div>
    </div>
  );
}
