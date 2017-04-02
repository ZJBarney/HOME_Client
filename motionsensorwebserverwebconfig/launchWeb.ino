void launchWeb(int webtype) {
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.print("Local IP: ");
  Serial.println(WiFi.localIP());
  Serial.print("SoftAP IP: ");
  Serial.println(WiFi.softAPIP());
  createWebServer(webtype);
  // Start the server
  server.begin();
  Serial.println("Server started"); 
}

void findBase()
{
  
  sprintf(hostString, "ESP_%06X", ESP.getChipId());
  Serial.print("Hostname: ");
  Serial.println(hostString);
  WiFi.hostname(hostString);

  while (WiFi.status() != WL_CONNECTED) {
    delay(250);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

 if (!MDNS.begin(hostString)) {
    Serial.println("Error setting up MDNS responder!");
  }

  Serial.println("Sending mDNS query");
  int n = MDNS.queryService("esp", "tcp"); // Send out query for esp tcp services
  Serial.println("mDNS query done");
  if (n == 0) {
    Serial.println("no services found");
  }
  else 
    baseIP = String(MDNS.IP(0)[0]) + '.' + String(MDNS.IP(0)[1]) + '.' + String(MDNS.IP(0)[2]) + '.' + String(MDNS.IP(0)[3]);
  Serial.println(baseIP);

  /******  Add initialization stuff to communicate to base and establish a program table or download existing table  *****/
  
}

