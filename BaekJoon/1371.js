function solution(input) {
  count = {};
  let max = 0;
  [...input].forEach((c) => {
    if (c.trim() === "") {
      return;
    }
    if (count[c] === undefined) {
      count[c] = 0;
    }
    count[c]++;
    max = Math.max(max, count[c]);
  });
  return Object.entries(count)
    .filter(([k, v]) => v === max)
    .map(([k, v]) => k)
    .sort()
    .join("");
}
// const filePath = "input.txt";
const filePath = "/dev/stdin";
const line = require("fs").readFileSync(filePath, "utf8");
let input = line.trim();
console.log(solution(input));
