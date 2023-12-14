function solution(n, input) {
  const groupA = Array.from({ length: 101 }, () => 0);
  const groupB = Array.from({ length: 101 }, () => 0);
  let ret = "";
  for (let i = 0; i < n; i++) {
    const [a, b] = input[i].split(" ");
    groupA[a]++;
    groupB[b]++;
    const countA = Array.from(groupA, (v) => v);
    const countB = Array.from(groupB, (v) => v);
    let cursorA = 1;
    let cursorB = 100;
    let answer = 0;
    while (true) {
      while (cursorA <= 100 && countA[cursorA] === 0) {
        cursorA++;
      }
      while (cursorB > 0 && countB[cursorB] === 0) {
        cursorB--;
      }
      if (cursorA > 100 || cursorB < 1) {
        break;
      }
      answer = Math.max(answer, cursorA + cursorB);
      if (countA[cursorA] > countB[cursorB]) {
        countA[cursorA] -= countB[cursorB];
        countB[cursorB] = 0;
      } else {
        countB[cursorB] -= countA[cursorA];
        countA[cursorA] = 0;
      }
    }
    ret = ret.concat(answer, "\n");
  }
  console.log(ret);
}
// const filePath = "input.txt";
const filePath = "/dev/stdin";
const line = require("fs").readFileSync(filePath, "utf8");
let [n, ...input] = line.trim().split("\n");
solution(n, input);
