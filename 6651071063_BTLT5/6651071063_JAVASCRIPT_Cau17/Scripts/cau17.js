function nhiPhanSangThapPhan(s) {
  var kq = 0, len = s.length;
  for (var i = 0; i < len; i++) {
    kq += parseInt(s.charAt(i)) * Math.pow(2, len - 1 - i);
  }
  return kq;
}
var bin = "11011011";
document.getElementById("kq").innerHTML = bin + "<sub>2</sub> = " + nhiPhanSangThapPhan(bin) + "<sub>10</sub>";
