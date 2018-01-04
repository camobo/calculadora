OBJETOS=main.o sources/op1.o sources/op2.o
CFLAGS= -I./headers
TARGET=calculadora
PACKETDIR=paqueteDeb
CUSTOMPATH=$(PACKETDIR)/usr/bin
DEBIAN=$(PACKETDIR)/DEBIAN
CONTROL=$(DEBIAN)/control
VERSION=1.0.0
TARGETDEB=$(TARGET)-$(VERSION).deb


$(TARGET):$(OBJETOS)
	gcc $(OBJETOS) -o $(TARGET)

%.o : %.c
	gcc $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJETOS) $(TARGET)

clean-all: clean
	rm -r $(PACKETDIR)
	rm $(TARGETDEB)

test:
	echo "${VERSION}"

control: $(TARGET)
	@(\
	mkdir -p $(CUSTOMPATH) $(DEBIAN);\
	cp $(TARGET) $(CUSTOMPATH);\
	echo "Package: calculadora" > $(CONTROL);\
	echo "Priority: optional" >> $(CONTROL);\
	echo "Section: misc" >> $(CONTROL);\
	echo "Maintainer: Carlos" >> $(CONTROL);\
	echo "Architecture: all" >> $(CONTROL);\
	echo "Version: ${VERSION}" >> $(CONTROL);\
	echo "Depends:" >> $(CONTROL);\
	echo "Description: Calculadora que suma mucho"  >> $(CONTROL);\
	echo " Paquete con un ejecutable de calculadora" >> $(CONTROL);\
	)

deb: control
	dpkg -b $(PACKETDIR) $(TARGETDEB);

install: $(TARGETDEB)
	dpkg -i $(TARGETDEB)

installYocto: $(TARGET)

unninstall: install

