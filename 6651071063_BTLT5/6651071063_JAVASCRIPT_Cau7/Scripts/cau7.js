var d = parseInt(prompt("Nhập ngày:"));
var m = parseInt(prompt("Nhập tháng:"));
var y = parseInt(prompt("Nhập năm:"));
function soNgayTrongThang(m, y) {
  if (m === 2) return ((y % 4 === 0 && y % 100 !== 0) || y % 400 === 0) ? 29 : 28;
  if (m === 4 || m === 6 || m === 9 || m === 11) return 30;
  return 31;
}
d++;
if (d > soNgayTrongThang(m, y)) {
  d = 1; m++;
  if (m > 12) { m = 1; y++; }
}
console.log("Ngày kế tiếp: " + d + "/" + m + "/" + y);
