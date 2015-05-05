package com.coolerfall.app;

import android.app.Application;

import com.coolerfall.watcher.Watcher;

import java.util.HashMap;
import java.util.Map;

/**
 * Application of this project.
 *
 * @author Vincent Cheung
 * @since  Jan. 23, 2015
 */
public class WatcherApp extends Application {
	private static final String URL = "http://www.xiami.com/member/login";

	@Override
	public void onCreate() {
		super.onCreate();

		Map<String, String> test = new HashMap<String, String>() {{
			put("deviceId","test");
			put("imei","test");
			put("appId","test");
			put("serverId","test");
			put("appVersion","test");
		}};
		Watcher.run(this, URL, test, true);
	}
}
