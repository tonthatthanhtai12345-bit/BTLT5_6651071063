function VietHoaDauTu(s) {
  return s.split(" ").map(function (w) {
    return w.charAt(0).toUpperCase() + w.slice(1);
  }).join(" ");
}
var chuoi = "need not to know";
document.getElementById("kq").innerText = '"' + chuoi + '" => "' + VietHoaDauTu(chuoi) + '"';
