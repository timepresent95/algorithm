function solution(sequence) {
  let answer = 0;
  const stack = [];
  sequence.split("").forEach((cur) => {
    if (cur === "(") {
      stack.push(cur);
    } else if (stack.length === 0) {
      answer++;
    } else {
      stack.pop();
    }
  });
  return answer + stack.length;
}

const readline = require("readline");
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

let input;

rl.on("line", function (line) {
  input = line;
  rl.close();
}).on("close", function () {
  console.log(solution(input));
  process.exit();
});
