function solution(sequence) {
  const { length } = sequence;
  const charValue = { "(": 1, ")": -1 };
  let prefixSumArr = [];
  prefixSumArr[0] = charValue[sequence[0]];
  let overTwoIndex = null;
  let firstNegativeIndex = prefixSumArr[0] < 0 ? 0 : null;
  for (let i = 1; i < sequence.length; i++) {
    prefixSumArr[i] = prefixSumArr[i - 1] + charValue[sequence[i]];
    if (overTwoIndex === null && prefixSumArr[i] >= 2) {
      overTwoIndex = i;
    }
    if (prefixSumArr[i] < 2) {
      overTwoIndex = null;
    }
    if (firstNegativeIndex === null && prefixSumArr[i] < 0) {
      firstNegativeIndex = i;
    }
  }
  const totalSum = prefixSumArr[length - 1];
  if (totalSum === 2) {
    return sequence
      .slice(overTwoIndex)
      .split("")
      .filter((v) => v === "(").length;
  }
  if (totalSum === -2) {
    return sequence
      .slice(0, firstNegativeIndex + 1)
      .split("")
      .filter((v) => v === ")").length;
  }
  return 0;
}

// const filePath = "input.txt";
const filePath = "/dev/stdin";
const line = require("fs").readFileSync(filePath, "utf8");
let input = line.trim();
console.log(solution(input, false));
