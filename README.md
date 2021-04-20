# PDFQRCodeReader

What is the PDF QR Code Reader?
The PDF QR Code Reader is a project created for Foxit Student Bounty Project.  This is a start project which has a lot of the code completed and is waiting for a student to become interested in the project and complete the rest of the code.  The goal of this project is to be able to read the QR code in the sample PDF and display that information for the user to see.

How to run the project?
1. Download and install Foxit PhantomPDF https://cdn06.foxitsoftware.com/pub/foxit/phantomPDF/desktop/win/10.x/10.1/en_us/FoxitPhantomPDF1011_enu_Setup_Website.msi
2. Install Microsoft Visual Studio 2017
3. Open "PDFQRCodeReader\Samples\RibbonElements\RibbonElements.sln" with Visual Studio 2017
4. Install any project dependancy Visual Studio 2017 indicates that you are missing.
5. Open Windows Explorer and go to "C:\Program Files (x86)\Foxit Software\Foxit PhantomPDF\"
6. Right click on the folder "plugins" and choose properties
7. Click on the "Security" Tab
8. Click on "Edit"
9. Select "Users" and check the box "Full Control"
10. Click "Apply"
11. Go back to Visaul Studio 2017 and build and run the project.

How to use the PDF QR Code Reader Plugin?
1. Open Foxit PhantomPDF
2. Open the PDF at PDFQRCodeReader\Samples\RibbonElements\RibbonElements\QRCodeSample.pdf
3. Locate and click on the "QR Plugin" Tab 
4. Click on "SelectQR"
5. Select the QR code on the PDF
6. Click on "ShowQRInfo"
7. See message (the code needs to be finish here).  Please see "PDFQRCodeReader\Samples\RibbonElements\RibbonElements\ElementsProc.cpp" -> CElementsProc::OnQRGetInfoButtonProc

Where can I find the APIs for Foxit PhantomPDF?
You can find the API reference at "PDFQRCodeReader\Document\Foxit Reader PDF API Reference.pdf"

For Support, please contact Huy_Tran@foxitsoftware.com
