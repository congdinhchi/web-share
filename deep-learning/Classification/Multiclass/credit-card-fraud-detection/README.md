#  Phát hiện gian lận thẻ tín dụng

## Giới thiệu 

**Bối cảnh**  
Hiện nay, tại các ngân hàng trong nước và quốc tế luôn có rất nhiều các giao dịch được thực hiện hàng ngày. Tuy nhiên, trong số đó có một phần rất nhỏ các kẻ gian lận tạo ra những giao dịch một cách bất thường nhằm chiếm đoạt khối tài sản của chủ thẻ.  

**Nội dung**  
Tập dữ liệu chứa các giao dịch vào tháng 9 năm 2013 của các chủ thẻ ở Châu Âu. Bộ dữ liệu bao gồm các giao dịch trong 2 ngày, trong đó có 492 giao dịch gian lận trong số 284,807 giao dịch.  

*Chú ý: Dữ liệu đã được biến đổi bằng PCA nhằm mục tiêu ẩn chứa thông tin của chủ thẻ. Chi tiết sẽ được đề cập trong phần "Data".

**Mục đích**  
Bạn hãy thay mặt đội ngũ phát hiện gian lận của ngân hàng, xây dựng một mô hình có thể giúp ngân hàng phát hiện được gian lận trong các giao dịch.  

## Dữ liệu  

**Dữ liệu bao gồm các phần sau**  
train-dataset.csv: tệp dữ liệu để huấn luyện mô hình thuật toán.  
test-dataset.csv: tệp dữ liệu kiểm thử trên hệ thống Kaggle [Dùng cho việc thực hiện dự đoán và nộp kết quả lên Kaggle]  
sample_submission.csv: tệp mẫu kết quả nộp lên Kaggle (30% dữ liệu Public và 70% dữ liệu Private trên Leaderboard Score)  

**Dữ liệu**  
Tập dữ liệu chứa các giao dịch vào tháng 9 năm 2013 của các chủ thẻ ở Châu Âu. Bộ dữ liệu bao gồm các giao dịch trong 2 ngày, trong đó có 492 giao dịch gian lận trong số 284,807 giao dịch.  

*Chi tiết về các trường dữ liệu:  

- Time: thời gian tính kể từ giao dịch đầu tiên khi thu thập dữ liệu này.  
- V1 ... V28: các trường dữ liệu này đã được chuyển đổi bằng PCA để đảm bảo quyền riêng tư cho chủ thẻ. (Các trường thông tin ẩn, chúng ta sẽ không biết đó là gì).  
- Amount: số tiền giao dịch.  
- Class: đánh giá xem có phải là gian lận hay không (Chỉ có 0 và 1).  
