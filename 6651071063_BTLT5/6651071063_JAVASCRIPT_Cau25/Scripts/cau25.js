var thucAn = { "Bún bò": 20000, "Hủ tiếu": 18000, "Bánh canh": 17000, "Phở bò": 19000, "Nuôi": 15000, "Bánh mì thịt": 12000, "Bánh cuốn": 15000 };
var nuocUong = { "Cà phê đá": 12000, "Cà phê sữa đá": 15000, "Chanh dây": 13000, "Chanh muối": 12000, "Xí muội": 14000, "Sữa tươi": 13000, "Cam vắt": 17000 };
function nap(id, ds) {
  var s = document.getElementById(id);
  for (var k in ds) s.options.add(new Option(k, k));
}
nap("thucan", thucAn);
nap("nuocuong", nuocUong);

function tinhTien() {
  var tong = 0;
  var html = '<table border="1" bgcolor="#99FFFF" width="60%"><tr><th>Các món đã dùng</th><th>Tiền</th></tr>';
  function duyet(id, ds) {
    var s = document.getElementById(id);
    for (var i = 0; i < s.options.length; i++) {
      if (s.options[i].selected) {
        var ten = s.options[i].value;
        html += "<tr><td>" + ten + "</td><td>" + ds[ten] + "</td></tr>";
        tong += ds[ten];
      }
    }
  }
  duyet("thucan", thucAn);
  duyet("nuocuong", nuocUong);
  var dem = document.querySelector('input[name="tg"]:checked').value === "dem";
  if (dem) {
    html += "<tr><td>Phụ thu ban đêm (10%)</td><td>" + tong * 0.1 + "</td></tr>";
    tong = tong * 1.1;
  }
  html += "<tr><td>Tổng tiền</td><td>" + Math.round(tong) + " đồng</td></tr></table>";
  document.getElementById("kq").innerHTML = html;
}
