function solution(input) {
  let answer = [];
  input = input.replaceAll(/<\/?main>/g, "");
  const divTags = input
    .split(/<div title="(.*?)">(.*?)<\/div>/)
    .filter((v) => v !== "");
  for (let i = 0; i < divTags.length; i++) {
    if (divTags[i][0] === "<") {
      const pTags = divTags[i].split(/<p>(.*?)<\/p>/);
      for (let j = 1; j < pTags.length; j += 2) {
        answer.push(
          pTags[j]
            .replaceAll(/<\/?[a-zA-Z ]*?>/g, "")
            .trim()
            .replaceAll(/ {2,}/g, " ")
        );
      }
    } else {
      const title = divTags[i].trim();
      answer.push(`title : ${title}`);
    }
  }
  console.log(answer.join("\n").trim());
}
// const filePath = "input.txt";
const filePath = "/dev/stdin";
const line = require("fs").readFileSync(filePath, "utf8");
let input = line.trim();
solution(input);
