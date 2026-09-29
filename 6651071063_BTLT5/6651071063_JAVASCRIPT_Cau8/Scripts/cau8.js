var n = parseInt(prompt("Nhập số nguyên có 2 chữ số (10-99):"));
var so = ["không","một","hai","ba","bốn","năm","sáu","bảy","tám","chín"];
if (isNaN(n) || n < 10 || n > 99) {
  window.alert("Vui lòng nhập số có 2 chữ số!");
} else {
  var chuc = Math.floor(n / 10), dv = n % 10, kq;
  if (chuc === 1) kq = "mười";
  else kq = so[chuc] + " mươi";
  if (dv !== 0) {
    if (dv === 5) kq += " lăm";
    else if (dv === 1 && chuc > 1) kq += " mốt";
    else kq += " " + so[dv];
  }
  window.alert(n + " đọc là: " + kq);
}
