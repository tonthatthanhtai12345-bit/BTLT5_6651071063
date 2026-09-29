var n = parseInt(prompt("Nhập số nguyên dương n:"));
var tong = 0, t = n;
while (t > 0) {
  tong += t;
  t = Math.floor(t / 2);
}
window.alert("Tổng n + n/2 + n/4 + ... = " + tong);
