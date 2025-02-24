package com.some.hwa1

import android.content.Context
import android.net.Uri
import android.os.Bundle
import android.support.v4.app.Fragment
import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import android.widget.ImageView
import android.widget.TextView

/**
 * @author Vad Nik.
 * @version dated June 08, 2018.
 * @link https://github.com/vadniks
 */
class FragmentResult : Fragment() {
    private var mParam1: String? = null
    private var mParam2: Int = 0
    private var mListener: OnFragmentInteractionListener? = null

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        if (arguments != null) {
            mParam1 = arguments!!.getString("weather")
            mParam2 = arguments!!.getInt("index")
        }
    }

    override fun onCreateView(inflater: LayoutInflater, container: ViewGroup?, savedInstanceState: Bundle?): View? {
        val view: View = inflater.inflate(R.layout.fragment_result, container, false)

        val text: TextView = view.findViewById(R.id.textFr)
        text.text = arguments?.get("weather").toString()

        println(arguments?.getInt("index")?.plus(1))

        val image: ImageView = view.findViewById(R.id.image)
        image.setImageResource(resources.getIdentifier("w" + arguments?.getInt("index")?.plus(1),
                "drawable", pkgName))
        //image.setImageResource(R.drawable.w1)

        return view
    }

//    // TODO: Rename method, update argument and hook method into UI event
//    fun onButtonPressed(uri: Uri) {
//        if (mListener != null) {
//            mListener!!.onFragmentInteraction(uri)
//        }
//    }

    override fun onAttach(context: Context?) {
        super.onAttach(context)
        if (context is OnFragmentInteractionListener)
            mListener = context
//        else
//            throw RuntimeException(context!!.toString() + " must implement OnFragmentInteractionListener")
    }

    override fun onDetach() {
        super.onDetach()
        mListener = null
    }

    /**
     * This interface must be implemented by activities that contain this
     * fragment to allow an interaction in this fragment to be communicated
     * to the activity and potentially other fragments contained in that
     * activity.
     *
     *
     * See the Android Training lesson [Communicating with Other Fragments](http://developer.android.com/training/basics/fragments/communicating.html) for more information.
     */
    internal interface OnFragmentInteractionListener {
        // TODO: Update argument type and name
        @Suppress("unused")
        fun onFragmentInteraction(uri: Uri)
    }

    internal companion object {
        private lateinit var pkgName: String

        internal fun newInstance(weather: String, index: Int, context: Context): FragmentResult {
            val fragment = FragmentResult()
            val args = Bundle()
            args.putString("weather", weather)
            args.putInt("index", index)
            fragment.arguments = args
            pkgName = context.packageName
            return fragment
        }
    }
}
