require 'net/smtp'

from_email = 'ahmet.erylmaz14@gmail.com'
to_email = 'uzali.kafasi@gmail.com'
subject = 'Email with attachment'
body = 'This email contains an attachment.'

attachment_filename = 'attachments/42.png'
attachment_data = File.read(attachment_filename)

smtp_server = 'https://smtp.gmail.com/'
smtp_port = 465
smtp_username = 'SMTP'
smtp_password = 'hqkoddaovhrgmfxy'

message = <<~MESSAGE
  From: #{from_email}
  To: #{to_email}
  Subject: #{subject}
  MIME-Version: 1.0
  Content-Type: multipart/mixed; boundary="boundary_string"

  --boundary_string
  Content-Type: text/plain; charset=UTF-8
  Content-Transfer-Encoding: 7bit

  #{body}

  --boundary_string
  Content-Type: text/plain; charset=UTF-8
  Content-Disposition: attachment; filename="#{attachment_filename}"
  Content-Transfer-Encoding: base64

  #{[attachment_data].pack('m')}
  --boundary_string--
MESSAGE

Net::SMTP.start(smtp_server, smtp_port, 'localhost', smtp_username, smtp_password, :login) do |smtp|
  smtp.send_message message, from_email, to_email
end
